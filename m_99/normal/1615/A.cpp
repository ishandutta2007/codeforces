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
		
		int s = 0;
		rep(i,n)s += a[i];
		
		if(s%n==0)s = 0;
		else s = 1;
		
		cout<<s<<endl;
		
	}
	
	return 0;
}