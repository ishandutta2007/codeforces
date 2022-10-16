#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	for(int i=1;i<m;i++)
		if(b[m-i]!=a[n-i]){
			cout<<"NO"<<endl;
			return;
		}
	int cnt=0;
	for(int i=0;i<=n-m;i++)
		if(a[i]==b[0])
			cnt=1;
	cout<<(cnt?"YES":"NO")<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}