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
		
		long long n,k;
		cin>>n>>k;
		vector<long long> s(k);
		rep(i,k)scanf("%lld",&s[i]);
		if(k==1){
			cout<<"YES"<<endl;
			continue;
		}
		bool f = true;
		rep(i,k-2){
			if(s[i+1]-s[i] > s[i+2]-s[i+1])f = false;
		}
		
		long long v = s[1] - s[0];
		v *= n-k + 1;
		if(v < s[0]){
			f = false;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}