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
		cin>>n;
		
		priority_queue<long long,vector<long long>,greater<long long>> Q;
		
		rep(i,n){
			long long a;
			scanf("%lld",&a);
			Q.push(a);
		}
		
		long long ans = Q.top();
		long long sum = 0LL;
		while(Q.size()>0){
			ans = max(ans,Q.top()-sum);
			sum += Q.top()-sum;
			Q.pop();
		}
		printf("%lld\n",ans);
		
	}
	
	return 0;
	
}