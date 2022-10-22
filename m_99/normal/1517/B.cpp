#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<pair<int,int>> P;
		rep(i,n){
			rep(j,m){
				int x;
				scanf("%d",&x);
				P.emplace_back(x,i);
			}
		}

		vector<vector<int>> ans(n,vector<int>(m,-1));
		
		
		
		sort(P.begin(),P.end());
		rep(i,m){
			ans[P[i].second][i] = P[i].first;
		}
		//cout<<'a'<<endl;
		vector<vector<int>> t(n);
		for(int i=m;i<P.size();i++){
			t[P[i].second].push_back(P[i].first);
		}
		//cout<<'a'<<endl;
		rep(i,n){
			rep(j,m){
				if(ans[i][j]==-1){
					ans[i][j] = t[i].back();
					t[i].pop_back();
				}
			}
		}
		//cout<<'a'<<endl;
		rep(i,n){
			rep(j,m){
				if(j!=0)printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
		//cout<<'a'<<endl;
	}
	
    return 0;
}