#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<pair<int,int>> P(m*n);
		rep(i,n){
			rep(j,m){
				int a;
				scanf("%d",&a);
				P[i*m+j] = make_pair(a,i*m+j);
			}
		}
		sort(P.begin(),P.end());
		
		vector t(n,vector<pair<int,int>>(m));
		
		rep(i,n){
			rep(j,m){
				t[i][j] = P[i*m+j];
				t[i][j].second *= -1;
			}
			sort(t[i].begin(),t[i].end());
		}
		
		vector<vector<int>> used(n);
		vector<pair<int,int>> ind(n*m);
		rep(i,n){
			rep(j,m){
				ind[t[i][j].second*-1] = make_pair(i,j);
			}
		}
		int ans = 0;
		rep(i,ind.size()){
			int y = ind[i].first,x = ind[i].second;
			rep(j,used[y].size()){
				if(x>used[y][j])ans++;
			}
			used[y].push_back(x);
		}
		
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}