#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


void Print(int k,vector<int> a){
	printf("%d\n",k);
	rep(i,a.size()){
		if(i!=0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> b(n+2);
		long long sum = 0;
		vector<vector<int>> E(n+2);
		vector<int> cnt(n+2);
		rep(i,n){
			scanf("%d",&b[i]);
			E[b[i]].push_back(i+1);
		}
		
		vector<int> ans;
		vector<bool> ok(n+2,false);
		rep(i,n+2){
			int u = i;
			if(i==1)u = n+1;
			else if(i>=2){
				u--;
			}
			if(ok[u])continue;
			
			queue<int> Q;
			Q.push(u);
			if(u!=0&&u!=n+1)ans.push_back(u);
			while(Q.size()>0){
				int uu = Q.front();
				//cout<<u<<','<<uu<<endl;
				Q.pop();
				ok[uu] = true;
				
				rep(j,E[uu].size()){
					int v = E[uu][j];
					if(E[v].size()==0){
						ans.push_back(v);
						ok[v] = true;
					}
					
				}
				rep(j,E[uu].size()){
					int v = E[uu][j];
					if(E[v].size()!=0){
						ans.push_back(v);
						Q.push(v);
					}
					
				}
			}
		}
		int k = 0;
		rep(i,E.size()){
			rep(j,E[i].size()){
				if(E[i][j]<i)k = max(k,E[i][j]);
			}
		}
		Print(k,ans);
	}
	
	return 0;
}