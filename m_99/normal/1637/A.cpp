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
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		auto b = a;
		sort(a.begin(),a.end());
		if(a==b)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
		
	}
	
	return 0;
}