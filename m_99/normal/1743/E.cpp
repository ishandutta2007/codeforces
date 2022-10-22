#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 3000000000000000

long long p[2],t[2];
long long s;

long long get(long long h){
	
	long long ok = Inf64,ng = -1;
	while(ok-ng>1LL){
		long long mid = (ok+ng)/2;
		__int128 c = 0;
		rep(i,2){
			__int128 tt = (mid / t[i]);
			tt *= p[i]-s;
			c += tt;
		}
		if(c>=h)ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
	
	rep(i,2)cin>>p[i]>>t[i];
	
	long long h;
	cin>>h>>s;
	
	vector<long long> dp(h+1,Inf64);
	dp[0] = 0;
	rep(i,h){
		for(long long j=1;j<=h;j++){
			rep(k,2){
				long long T = t[k];
				T *= j;
				if(T < t[k^1])continue;
				long long d = (j-1) * (p[k]-s);
				long long X = T/t[k^1];
				d += (X-1) * (p[k^1]-s);
				d += (p[k]+p[k^1]-s);
				long long nj = min(h,i+d);
				long long nv = dp[i];
				nv += T;
				dp[nj] = min(dp[nj],nv);
			}
		}
	}
			
	
	long long ans = Inf64;
	rep(i,h+1){
		ans = min(ans,dp[i] + get(h-i));
	}
	cout<<ans<<endl;
	
	return 0;
}