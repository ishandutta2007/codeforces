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
		vector<long long> a(n),b(n);
		rep(i,n)cin>>a[i];
		rep(i,n)cin>>b[i];
		long long ans = 0;
		rep(i,n-1){
			ans += min(abs(a[i]-a[i+1]) + abs(b[i]-b[i+1]), abs(a[i]-b[i+1]) + abs(b[i]-a[i+1]));
		}
		cout<<ans<<endl;
			
		
		
	}
	
	return 0;
}