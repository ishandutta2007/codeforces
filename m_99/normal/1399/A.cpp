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
		bool f = true;
		rep(i,n-1){
			if(abs(a[i]-a[i+1])<=1){
			}
			else f = false;
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
	}
	
	return 0;
}