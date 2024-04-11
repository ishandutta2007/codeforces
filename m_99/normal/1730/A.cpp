#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,c;
		cin>>n>>c;
		
		vector cnt(105,0);
		rep(i,n){
			int a;
			cin>>a;
			cnt[a]++;
		}
		int ans = 0;
		rep(i,105){
			if(cnt[i]<c)ans += cnt[i];
			else ans += c;
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}