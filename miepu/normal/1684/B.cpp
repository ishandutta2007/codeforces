#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int a,b,c;cin>>a>>b>>c;
	cout<<a+b+c<<' '<<c+b<<' '<<c<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}