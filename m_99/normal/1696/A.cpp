#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,z;
		cin>>n>>z;
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		int ans = 0;
		rep(i,n){
			ans = max(ans,a[i]|z);
		}
		cout<<ans<<endl;
		
		
	}
	
    return 0;
}