#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	rep(i,m){
		int c;
		cin>>c;
		c--;
		a[c]++;
	}
	
	int ans = Inf;
	rep(i,n)ans = min(ans,a[i]);


	cout<<ans<<endl;
	
    return 0;
}