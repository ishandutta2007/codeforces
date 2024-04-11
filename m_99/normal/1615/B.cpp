#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
int sum[19][200005];
int main(){
	
	rep(i,19){
		rep(j,200005){
			if((j>>i)&1)sum[i][j] = 1;
		}
	}
	rep(i,19){
		rep(j,200004)sum[i][j+1] += sum[i][j];
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int l,r;
		cin>>l>>r;
		
		int ans = Inf;
		rep(i,19){
			int S = sum[i][r] - sum[i][l-1];
			S = (r-l+1) - S;
			ans = min(ans,S);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}