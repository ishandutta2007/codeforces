#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,k;
		cin>>n>>k;
		
		long long ans = 0LL;
		long long cur = 1LL;
		while(cur!=n){
			long long t = min(k,cur);
			if(t==k){
				ans += (n-cur+t-1)/t;
				break;
			}
			else{
				cur += t;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}