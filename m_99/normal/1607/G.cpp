#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){	
	
	int _t;
	cin>>_t;
	
	for(int _=1;_<=_t;_++){
		
		int n;
		long long m;
		scanf("%d %lld",&n, &m);
		
		vector<long long> a(n),b(n);
		rep(i,n){
			scanf("%d %d",&a[i],&b[i]);
		}
		
		vector<long long> x(n),y(n,0);
		long long ans = 0LL;
		rep(i,n){
			if(a[i]>=m){
				x[i] = m;
			}
			else{
				x[i] = a[i];
				y[i] = m-a[i];
			}
			ans += (a[i]-x[i]) - (b[i]-y[i]);
		}
		//cout<<ans<<endl;
		if(ans<0){
			rep(i,n){
				long long t = abs(ans)/2;
				t = min({t,x[i],b[i]-y[i]});
				ans += t*2;
				x[i] -= t;
				y[i] += t;
			}
		}
		printf("%lld\n",abs(ans));
		rep(i,n){
			printf("%lld %lld\n",x[i],y[i]);
		}
	}
	
	return 0;
	
}