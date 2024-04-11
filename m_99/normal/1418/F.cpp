#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	long long n,m;
	cin>>n>>m;
	
	vector<vector<int>> Yn(n+1,vector<int>()),Ym(m+1,vector<int>());
	map<int,int> S;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			Yn[j].push_back(i);
		}
	}
	
	
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j+=i){
			Ym[j].push_back(i);
		}
	}
	
	long long l = m+1,r = m;
	
	long long L,R;
	cin>>L>>R;
	vector<int> memo(n+m+1,0);
	for(long long i=1;i<=n;i++){
		long long tol = (L+i-1)/i;
		long long tor = min(m,R/i);

		if(tor-tol>=0){
			while(l<tol){
				rep(j,Ym[l].size()){
					if(memo[Ym[l][j]]==l){
						S.erase(Ym[l][j]);
						memo[Ym[l][j]]=0;
					}
				}
				l++;
			}
			while(l>tol){
				l--;
				rep(j,Ym[l].size()){
					S[Ym[l][j]] = l;
					memo[Ym[l][j]]=l;
				}
			}
			
			while(r>tor){
				rep(j,Ym[r].size()){
					if(memo[Ym[r][j]]==r){
						S.erase(Ym[r][j]);
						memo[Ym[r][j]]=0;
					}
				}
				r--;
			}			

			bool f = false;
			rep(j,Yn[i].size()){
				auto it = S.upper_bound(Yn[i][j]);
				if(it==S.end())continue;
				if(i/Yn[i][j]*(it->first)>n)continue;
				printf("%d %d %d %d\n",i,it->second,i/Yn[i][j]*(it->first),(it->second)/(it->first)*Yn[i][j]);
				f=true;
				break;
			}
			if(!f){
				printf("-1\n");
			}
			
		}
		else{
			printf("-1\n");
		}
		
	}
	
	
	
    return 0;
}