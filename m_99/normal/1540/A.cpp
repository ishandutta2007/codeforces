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
		vector<long long> d(n);
		rep(i,n){
			scanf("%lld",&d[i]);
		}
		
		sort(d.begin(),d.end());
		
		long long ans = 0LL;
		
		long long sum = 0LL;
		long long cnt = 0LL;
		rep(i,n){
			if(i>=2){
				cnt++;
				sum += d[i-2];
			}
			ans -= sum;
			ans += cnt * d[i];
		}
		
		ans *= -1;
		
		printf("%lld\n",ans);
		
		
		
	}
	
    return 0;
}