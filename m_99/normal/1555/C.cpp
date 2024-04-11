#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int m;
		cin>>m;
		
		vector a(2,vector<long long>(m));
		rep(i,2){
			rep(j,m){
				scanf("%lld",&a[i][j]);
			}
		}
		
		vector<long long> M(m,0LL);
		
		long long cur = 0LL;
		rep(i,m){
			M[i] = cur;
			cur += a[1][i];
		}
		
		cur = 0LL;
		for(int i=m-1;i>=0;i--){
			M[i] = max(M[i],cur);
			cur += a[0][i];
		}
		
		long long ans = Inf;
		rep(i,m)ans = min(ans,M[i]);
		
		printf("%lld\n",ans);
		
	}
	
	return 0;
}