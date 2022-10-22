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
		int m,M;
		rep(i,n){
			cin>>a[i];
			if(a[i]==1)m = i+1;
			if(a[i]==n)M = i+1;
		}
		int ans = max(m,M);
		ans = min(ans,n+1-min(m,M));
		ans = min(ans,min(m,M) + (n+1-max(m,M)));
		
		cout<<ans<<endl;
	
	}
	return 0;
}