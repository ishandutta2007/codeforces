#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		vector<int> p(n);
		rep(i,n)cin>>p[i];
		
		int ans = 0;
		rep(i,k){
			if(p[i] > k)ans++;
		}
		cout<<ans<<endl;
		
		
	}
	
    return 0;
}