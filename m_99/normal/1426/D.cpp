#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005

int main(){

	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	
	set<long long> S;
	int ans = 0;
	long long sum = 0LL;
	S.insert(0LL);
	rep(i,n){
		sum += a[i];
		if(S.count(sum)){
			sum = a[i];
			ans++;
			S.clear();
			S.insert(a[i]);
			S.insert(0);
		}
		else S.insert(sum);
	}
	
	cout<<ans<<endl;
	
	return 0;
}