#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		vector<int> a(3);
		rep(i,3)cin>>a[i];
		sort(a.begin(),a.end());
		
		long long t = a[2]-a[1];
		t -= a[1]-a[0];
		t %= 3;
		if(t==0)cout<<0<<endl;
		else cout<<1<<endl;
		
		
		
		
	}
	
	return 0;
}