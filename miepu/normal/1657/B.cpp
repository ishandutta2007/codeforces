#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,b,x,y;
	int res=0,nw=0;
	cin>>n>>b>>x>>y;
	for(int i=1;i<=n;i++){
		if(nw+x<=b)nw+=x;
		else nw-=y;
		res+=nw;
	}
	cout<<res<<endl; 
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}