#include<cstdio>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> e[111111], e2[111111];
map<int,int> mp, mp2;

const int Z = 100;
int ff[222222];
unordered_map<int,int> z[222222];
/*
int d[222222];
long long int s2[222222], s[222222];
*/
bool sol(){
/*	for(int i=1; i<=n; i++)d[i] = (int)e[i-1].size();
	sort(d+1,d+n+1);
	for(int i=1; i<=n; i++){
		s[i] = s[i-1] + d[i];
		s2[i] = s2[i-1] + d[i] * (d[i] - 1LL) / 2;
	}
	long long int bes = (long long int)1e18;
	Z = 0;
	for(int i=0; i<=n; i++){
		long long int cur = s2[i] + (s[n] - s[i]) * s[n];
		if(cur < bes)bes = cur, Z = d[i];
	}
*/
	if(n < 1000){
		for(int i=0; i <= m+5; i++){
			ff[i] = 0;
		}
		for(int i=0; i<n; i++){
			for(auto x : e[i])ff[x] = i+1;
			for(int j=i+1; j<n; j++){
				int cnt = 0;
				for(auto x : e[j]){
					if(ff[x] == i+1){
						cnt ++;
						if(cnt == 2){
							printf("%d %d\n",i+1, j+1);
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	for(int i=0; i<=m+5; i++){
		ff[i] = 0;
		z[i].clear();
	}
	int W = 0;
	for(int i=0; i<n; i++)if(e[i].size() <= Z){
		int sz = e[i].size();
		for(int t1=0; t1<sz; t1++){
			int xx = e[i][t1];
			for(int t2=t1+1; t2<sz; t2++){
				int yy = e[i][t2];
				if(z[xx].count(yy)){
					printf("%d %d\n",z[xx][yy],i+1);
					return true;
				}
				z[xx][yy] = i+1;
				++W;
//				if(W >= 1000000)return false;
			}
		}
	}
	for(int i=0; i<n; i++)if(e[i].size() > Z){
		for(auto x : e[i])ff[x] = i+1;
		for(int j=0; j<n; j++){
			if(j == i)continue;
			if(j < i && e[j].size() <= Z || j > i){
				int cnt = 0;
				for(auto x : e[j]){
					if(ff[x] == i+1){
						cnt ++;
						if(cnt == 2){
							printf("%d %d\n",i+1, j+1);
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}
int main(){
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%d",&n);
		mp2.clear();
		for(int i=0; i<n; i++){
			int x,y;
			e2[i].clear();
			for(scanf("%d",&x);x--;){
				scanf("%d",&y);
				e2[i].push_back(y);
				mp2[y]++;
			}
		}
		mp.clear();m = 0;
		for(auto P : mp2)if(P.second > 1)
			mp[P.first] = ++m;
		for(int i=0; i<n; i++){
			e[i].clear();
			for(auto x : e2[i]){
				if(mp.count(x))
					e[i].push_back(mp[x]);
			}
			sort(e[i].begin(),e[i].end());
		}
		if(!sol())puts("-1");
	}
	return 0;
}