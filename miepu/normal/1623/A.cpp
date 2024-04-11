#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,m,a,b,c,d;cin>>n>>m>>a>>b>>c>>d;
	int res=1e18;
	if(c>=a)res=min(res,c-a);else res=min(res,n-a+n-c);
	if(d>=b)res=min(res,d-b);else res=min(res,m-b+m-d);
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}