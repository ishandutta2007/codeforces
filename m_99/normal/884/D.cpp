#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300000000000

int main(){	
	
	int n;
	cin>>n;
	

	vector<long long> a(n);
	priority_queue<long long,vector<long long>,greater<long long>> Q;
	rep(i,n){
		scanf("%lld",&a[i]);
		Q.push(a[i]);
	}
	
	long long ans = 0LL;
	
	while(Q.size()>1){
		int b = Q.size()%2;
		long long S = 0LL;
		rep(i,2 + b){
			S += Q.top();
			Q.pop();
		}
		ans += S;
		Q.push(S);
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}