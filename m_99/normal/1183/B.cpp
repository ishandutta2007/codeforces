#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
//	_t = 1;
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		sort(a.begin(),a.end());
		
		int ans = a[0] + k;
		if(abs(ans-a.back())>k){
			ans = -1;
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}