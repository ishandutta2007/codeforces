#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int x,y;cin>>x>>y;
	int t=sqrt(x*x+y*y);
	if(x==0&&y==0)cout<<0<<endl;
	else if(t*t==x*x+y*y)cout<<1<<endl;
	else cout<<2<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}