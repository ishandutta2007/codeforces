#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000

long long calc(long long a,long long b,long long c,long long d,bool f = false){
	long long ret = -Inf;
	if(a<=c&&a<=d&&c<=b&&d<=b)ret = abs(a-c)+abs(d-b);
	if(a<=c&&c<=b&&c<=d)ret = max(ret,abs(a-c) + abs(b-d));
	if(!f){
		ret = max(ret,calc(c,d,a,b,true));
	}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<long long> c(n);
		long long ans = 0LL;
		rep(i,n){
			scanf("%lld",&c[i]);
			//ans = max(ans,c[i]);
		}
		
		vector<long long> a(n),b(n);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n)scanf("%lld",&b[i]);
		
		vector<long long> Left(n,-Inf),Right(n,-Inf);
		vector<long long> Mid(n,-Inf);
		rep(i,n){
			if(i!=n-1){
				Left[i] = abs(a[i+1]-b[i+1])+1;
			}
			if(i!=0){
				Right[i] = c[i];
			}
			if(i!=0&&i!=n-1){
				long long x = a[i+1],y = b[i+1];//,z = a[i+1],w = b[i+1];
				if(x==y)continue;
				if(x>y)swap(x,y);
				Mid[i] = abs(x-1) + abs(c[i]-y) + 2;
				
			}
		}
		
		vector dp(n+1,vector<long long>(5,-Inf));
		dp[0][0] = 0LL;
		
		rep(i,n){
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = max(dp[i+1][1],dp[i][0] + Left[i]);
			dp[i+1][2] = max(dp[i+1][2],dp[i][1] + Mid[i]);
			dp[i+1][2] = max(dp[i+1][2],dp[i][2] + Mid[i]);
			dp[i+1][3] = max(dp[i+1][3],dp[i][1] + Right[i]);
			dp[i+1][3] = max(dp[i+1][3],dp[i][2] + Right[i]);
			dp[i+1][4] = max({dp[i+1][4],dp[i][3],dp[i][4]});
		}
		/*
		rep(i,n){
			cout<<Left[i]<<','<<Right[i]<<','<<Mid[i]<<endl;
			rep(j,5){
				//cout<<dp[i][j]<<',';
			}
			cout<<endl;
		}
		*/
		
		
		
		rep(i,5){
			if(i>=3)ans = max(ans,dp.back()[i]);
		}
		printf("%lld\n",ans);
		
		
	}
	
    return 0;
}