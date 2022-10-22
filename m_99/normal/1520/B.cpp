#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	vector<long long> L;
	for(int i=1;i<=9;i++){
		long long cur = 0;
		rep(j,10){
			cur *= 10;
			cur += i;
			L.push_back(cur);
		}
	}
	
	sort(L.begin(),L.end());
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n;
		cin>>n;
		
		int ans = distance(L.begin(),upper_bound(L.begin(),L.end(),n));
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}