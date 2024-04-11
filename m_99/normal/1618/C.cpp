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
		
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		long long ans = 0LL;
		{
			long long g = 0;
			for(int i=0;i<n;i+=2){
				g = gcd(a[i],g);
			}
			if(g!=1){
				for(int i=1;i<n;i+=2){
					if(a[i]%g==0){
						g = 1;
					}
				}
				//cout<<g<<endl;
				if(g!=1)ans = g;
			}
		}
		{
			long long g = 0;
			for(int i=1;i<n;i+=2){
				g = gcd(a[i],g);
			}
			if(g!=1){
				for(int i=0;i<n;i+=2){
					if(a[i]%g==0){
						g = 1;
					}
				}
				//cout<<g<<endl;
				if(g!=1)ans = g;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}