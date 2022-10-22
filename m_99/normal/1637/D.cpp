#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		vector<int> b(n);
		rep(i,n)scanf("%d",&b[i]);
		
		vector<bool> dp(100*n+5,false);
		dp[0] = true;
		long long s = 0;
		long long ss = 0;
		rep(i,n){
			vector<bool> ndp(100*n+5,false);
			rep(j,100*n+5){
				if(dp[j]==false)continue;
				ndp[j+a[i]] = true;
				ndp[j+b[i]] = true;
			}
			swap(dp,ndp);
			s += a[i] + b[i];
			ss += a[i]*a[i];
			ss += b[i]*b[i];
		}
		
		long long ans = 1000000000000000000;
		rep(i,100*n+5){
			if(dp[i]==false)continue;
			long long c = i*i;
			c += (s-i) * (s-i);
			c -= ss;
			ans = min(ans,c);
		}
		//cout<<ans<<endl;
		ans /= 2;
		ans *= 2;
		ans += (n-1) * ss;
		//ans += ss * n;
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}