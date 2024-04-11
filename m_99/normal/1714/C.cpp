#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int s;
		cin>>s;
		long long  ans = 100000000000000;
		rep(i,1<<9){
			long long cur = 0;
			int ss = 0;
			rep(j,9){
				if((i>>j)&1){
					cur *= 10;
					cur += j+1;
					ss += j+1;
				}
			}
			if(ss==s)ans = min(ans,cur);
			
		}
		cout<<ans<<endl;
	}
	
    return 0;
}