#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<long long> a(n);
		vector<long long> s(k,0);
		rep(i,n){
			cin>>a[i];
			s[i%k] = max(s[i%k],a[i]);
		}
		long long ans = 0;
		rep(i,k)ans += s[i];
		cout<<ans<<endl;
		
	}
	
	return 0;
}