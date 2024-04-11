#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		long long m;
		scanf("%lld",&m);
		
		vector<long long> a(n);
		vector<long long> b(n);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n)scanf("%lld",&b[i]);
		
		vector P(2,vector<long long>());
		rep(i,n){
			P[b[i]-1].push_back(a[i]);
		}
		rep(i,2)sort(P[i].rbegin(),P[i].rend());
		
		rep(i,2){
			P[i].insert(P[i].begin(),0LL);
			rep(j,P[i].size()){
				if(j==0)continue;
				P[i][j] += P[i][j-1];
			}
		}
		int ans = Inf;
		rep(i,P[0].size()){
			long long remain = m - P[0][i];
			int d = distance(P[1].begin(),lower_bound(P[1].begin(),P[1].end(),remain));
			if(d==P[1].size())continue;
			ans = min(ans,i + 2*d);
		}
		
		if(ans==Inf)printf("-1\n");
		else printf("%d\n",ans);
		
	}
	
    return 0;
}