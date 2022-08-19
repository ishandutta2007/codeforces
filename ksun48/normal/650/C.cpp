#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> a[1000000];
vector<int> c[1000000];
pair<int, pair<int,int> > val[1000000];
int rowmax[1000000];
int colmax[1000000];
int rvis[1000000];
int cvis[1000000];
vector<int> radj[1000000];
vector<int> cadj[1000000];
int sz = 0;
int maxused = 0;
void dfs1(int type, int k){ // compute maxused
	if(type == 0){
		if(rvis[k] == 1) return;
		rvis[k] = 1;
		maxused = max(maxused, rowmax[k]);
		for(int i = 0; i < radj[k].size(); i++){
			dfs1(1, radj[k][i]);
		}
	} else {
		if(cvis[k] == 1) return;
		cvis[k] = 1;
		maxused = max(maxused, colmax[k]);
		for(int i = 0; i < cadj[k].size(); i++){
			dfs1(0, cadj[k][i]);
		}
	}
}
void dfs2(int type, int k){ // compute maxused
	if(type == 0){
		if(rvis[k] == 0) return;
		rvis[k] = 0;
		for(int i = 0; i < radj[k].size(); i++){
			c[k][radj[k][i]] = maxused+1;
			rowmax[k] = maxused+1;
			colmax[radj[k][i]] = maxused+1;
			dfs2(1, radj[k][i]);
		}
	} else {
		if(cvis[k] == 0) return;
		cvis[k] = 0;
		for(int i = 0; i < cadj[k].size(); i++){
			dfs2(0, cadj[k][i]);
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			rowmax[i] = 0;
			colmax[j] = 0;
			int r;
			scanf("%d", &r);
			a[i].push_back(r);
			c[i].push_back(-1);
			val[sz].first = r;
			val[sz].second.first = i;
			val[sz].second.second = j;
			sz++;
		}
	}
	sort(val, val+sz);
	int cur = 0;
	while(cur < sz){
		int r = cur;
		while(r+1 < sz && val[cur].first == val[r+1].first){
			r++;
		}
		for(int i = cur; i <= r; i++){
			radj[val[i].second.first].push_back(val[i].second.second);
			cadj[val[i].second.second].push_back(val[i].second.first);
		}
		for(int i = cur; i <= r; i++){
			if(c[val[i].second.first][val[i].second.second] == -1){
				maxused = 0;
				dfs1(0,val[i].second.first);
				dfs2(0,val[i].second.first);
			}
		}
		for(int i = cur; i <= r; i++){
			radj[val[i].second.first].pop_back();
			cadj[val[i].second.second].pop_back();
		}
		cur = r+1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}