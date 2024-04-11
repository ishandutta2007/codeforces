#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,n,S;
		cin>>a>>b>>n>>S;
		
		int t = min(a,S/n);
		S -= t*n;
		
		if(S<=b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
	}
	
	return 0;
}