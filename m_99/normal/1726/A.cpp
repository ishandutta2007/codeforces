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
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		int ans = -Inf32;
		rep(i,n-1){
			ans = max(ans,a[n-1] - a[i]);
		}
		for(int i=1;i<n;i++)ans = max(ans,a[i]-a[0]);
		rep(i,n){
			int x = n-1 + i;
			int y = i;
			x %= n;
			ans = max(ans,a[x] - a[y]);
		}
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}