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
		vector<long long> a(n);
		rep(i,n){
			cin>>a[i];
		}
		
		int r = 0;
		long long ans = 0;
		rep(i,n-1){
			if(a[i]==0)continue;
			r = max(r,i);
			while(r!=n-1 && a[r]!=0)r++;
			if(r==n-1){
				ans += a[i];
				continue;
			}
			else{
				a[r] ++;
				a[i] --;
				ans++;
				i--;
				continue;
			}
		}
		cout<<ans<<endl;
		
	}
	
	
    return 0;
}