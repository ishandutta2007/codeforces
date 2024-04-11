#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n,q;
	scanf("%d %d",&n,&q);
	
	vector<vector<int>> X(n);
	
	rep(i,q){
		int l,r;
		scanf("%d %d",&l,&r);
		l--;
		for(int j=l;j<r;j++){
			if(X[j].size()<3){
				X[j].push_back(i);
			}
		}
	}
	
	int sum = 0;
	rep(i,n){
		if(X[i].size()>0)sum++;
	}
	
	vector ans(q,vector<int>(q,sum));
	
	rep(i,n){
		if(X[i].size()==2){
			ans[X[i][0]][X[i][1]]--;
			ans[X[i][1]][X[i][0]]--;
		}
		if(X[i].size()==1){
			rep(j,q){
				ans[X[i][0]][j]--;
				ans[j][X[i][0]]--;
			}
		}
	}
	
	int Ans = 0;
	rep(i,q){
		rep(j,q){
			if(i==j)continue;
			Ans = max(Ans,ans[i][j]);
		}
	}
	
	cout<<Ans<<endl;
	
	return 0;
}