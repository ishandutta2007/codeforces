#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main() {
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	
	long long ans = n;
	ans *= n+1;
	ans /= 2;
	rep(i,n-1){
		if(a[i]!=a[i+1]){
			long long x = i+1;
			long long y = n-(i+1);
			ans += x*y;
		}
	}
	
	rep(_,m){
		int i,z;
		cin>>i>>z;
		i--;
		rep(j,2){
			int aa = i-1+j;
			int bb = aa+1;
			if(aa<0 || bb>=n)continue;
			if(a[aa]!=a[bb]){
				long long x = aa+1;
				long long y = n-bb;
				ans -= x*y;
			}
		}
		a[i] = z;
		rep(j,2){
			int aa = i-1+j;
			int bb = aa+1;
			if(aa<0 || bb>=n)continue;
			if(a[aa]!=a[bb]){
				long long x = aa+1;
				long long y = n-bb;
				ans += x*y;
			}
		}
		cout<<ans<<endl;
	}
	
    return 0;
}