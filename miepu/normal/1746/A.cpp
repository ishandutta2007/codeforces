#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;s+=x;
	}
	cout<<(s?"YES":"NO")<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}