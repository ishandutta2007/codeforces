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
		int ans = 0;
		rep(i,30){
			rep(j,n){
				if((a[j]>>i)&1){
					ans |= 1<<i;
					break;
				}
			}
		}
		cout<<ans<<endl;
		
		
		
	}
	
	return 0;
}