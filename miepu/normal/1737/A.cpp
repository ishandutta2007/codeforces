#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int cnt[500];

void solve(){
	memset(cnt,0,sizeof(cnt));
	int n,k;cin>>n>>k;k=n/k;
	string s;cin>>s;
	for(auto x:s)cnt[x]++;
	for(int i=1;i<=n/k;i++){
		int nw='a',j=0;
		while(cnt[nw]&&j<k)cnt[nw]--,nw++,j++;
		cout<<(char)nw;
	}
	cout<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}