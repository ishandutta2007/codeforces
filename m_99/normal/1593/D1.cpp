#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		long long g=  0;
		rep(i,n){
			rep(j,n){
				g = gcd(g,abs(a[i]-a[j]));
			}
		}
		if(g==0)g = -1;
		cout<<g<<endl;
		
	}
	
	return 0;
}