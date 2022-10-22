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
		
		vector<int> a(n);
		vector<int> b(n);
		rep(i,n)cin>>a[i];
		rep(i,n)cin>>b[i];
		
		long long am = Inf,bm = Inf;
		rep(i,n){
			am = min(am,(long long)a[i]);
			bm = min(bm,(long long)b[i]);
		}
		
		long long ans = 0LL;
		
		rep(i,n){
			ans += max(a[i]-am,b[i]-bm);
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}