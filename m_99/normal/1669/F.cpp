#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		deque<long long> D(n);
		rep(i,n){
			cin>>D[i];
		}
		int ans = 0;
		long long S= 0;
		while(D.size()!=0){
			if(S>=0){
				S -= D.front();
				D.pop_front();
			}
			else{
				S += D.back();
				D.pop_back();
			}
			if(S==0){
				ans = max(ans,n-  (int)D.size());
			}
		}
		cout<<ans<<endl;
	}
	
	
    return 0;
}