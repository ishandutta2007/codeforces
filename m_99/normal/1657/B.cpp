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
		long long b,x,y;
		cin>>b>>x>>y;
		long long c = 0;
		long long ans = 0;
		rep(i,n){
			if(c+x>b)c -= y;
			else c += x;
			ans += c;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}