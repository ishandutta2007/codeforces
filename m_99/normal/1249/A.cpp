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
		rep(i,n)cin>>a[i];
		sort(a.begin(),a.end());
		
		int ans = 1;
		rep(i,n){
			if(i!=0 && abs(a[i]-a[i-1])==1){
				ans++;
				break;
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}