#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		long long c;
		scanf("%lld",&c);
		
		vector<long long> a(n),b(n-1);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n-1)scanf("%lld",&b[i]);
		
		long long money = 0LL,days = 0LL;
		long long ans = Inf;
		
		rep(i,n){
			//cout<<money<<endl;
			long long x = max(0LL,c - money);
			ans = min(ans,(x + a[i]-1) / a[i] + days);
			
			if(i!=n-1){
				x = max(0LL,b[i] - money);
				x = (x+a[i]-1)/a[i];
				days += x+1;
				money += x * a[i];
				money -= b[i];
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}