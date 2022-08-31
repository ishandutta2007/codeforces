#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
int h[500000]; //actual heights
vector<int> queries[500000]; // b
vector<int> idx[500000]; // 
vector<int> maxusing[500000]; // not counting x
int c[500000]; // is necessary in LIS
int sad[500000];
int ans[500000];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &h[i]);
		c[i] = 0;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		queries[a-1].push_back(b);
		idx[a-1].push_back(i);
		maxusing[a-1].push_back(0);
	}
	vector<int> lis;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < queries[i].size(); j++){
			int b = queries[i][j];
			int s = -1;
			int e = lis.size();
			while(s + 1 < e){
				int m = (s+e)/2;
				if(h[lis[m]] < b){
					s = m;
				} else {
					e = m;
				}
			}
			maxusing[i][j] += e;
		}
		int s = -1;
		int e = lis.size();
		if(lis.size() == 0 || h[lis[lis.size()-1]] < h[i]){
			lis.push_back(-1);
		}
		while(s + 1 < e){
			int m = (s+e)/2;
			if(h[i] <= h[lis[m]]){
				e = m;
			} else {
				s = m;
			}
		}
		lis[e] = i;
		if(e == 0){
			sad[i] = -1;
		} else {
			sad[i] = lis[e-1];
		}
	}
	int r = lis[lis.size()-1];
	while(r >= 0){
		c[r]++;
		r = sad[r];
	}
	lis.clear();
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < queries[i].size(); j++){
			int b = queries[i][j];
			int s = -1;
			int e = lis.size();
			while(s + 1 < e){
				int m = (s+e)/2;
				if(h[lis[m]] > b){
					s = m;
				} else {
					e = m;
				}
			}
			maxusing[i][j] += e;
		}
		if(lis.size() == 0 || h[lis[lis.size()-1]] > h[i]){
			lis.push_back(-1);
		}
		int s = -1;
		int e = lis.size();
		while(s + 1 < e){
			int m = (s+e)/2;
			if(h[i] >= h[lis[m]]){
				e = m;
			} else {
				s = m;
			}
		}
		lis[e] = i;
		if(e == 0){
			sad[i] = -1;
		} else {
			sad[i] = lis[e-1];
		}
	}
	r = lis[lis.size()-1];
	while(r >= 0){
		c[r]++;
		r = sad[r];
	}
	int z = lis.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < queries[i].size(); j++){
			if(c[i] == 2){
				ans[idx[i][j]] = max(maxusing[i][j]+1,z-1);
			} else {
				ans[idx[i][j]] = max(maxusing[i][j]+1,z);
			}
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
 
}