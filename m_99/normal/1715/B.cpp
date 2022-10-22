#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n,k,b,s;
		cin>>n>>k>>b>>s;
		vector<long long> ans(n,0);
		bool f = false;
		rep(i,n){
			long long ss = s;
			ss -= (k-1) * i;
			if(ss < 0)continue;
			if(ss/k == b){
				rep(j,i)ans[j] = k-1;
				ans.back() = ss;
				f = true;
				break;
			}
		}
		if(f){
			rep(i,n){
				if(i!=0)cout<<' ';
				cout<<ans[i];
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	
    return 0;
}