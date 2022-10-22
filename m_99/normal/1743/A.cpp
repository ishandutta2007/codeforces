#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		bool f[10];
		rep(i,10)f[i] = false;
		int n;
		cin>>n;
		rep(i,n){
			int a;
			cin>>a;
			f[a] = true;
		}
		int ans = 0;
		rep(i,10){
			for(int j=i+1;j<10;j++){
				if(f[i]||f[j])continue;
				ans += 6;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}