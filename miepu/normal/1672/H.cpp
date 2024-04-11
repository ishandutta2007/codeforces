#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int sm[2][N];
int n,q;
string s; 

void solve(){
	cin>>n>>q;
	cin>>s,s='0'+s;
	for(int i=2;i<=n;i++){
		sm[0][i]=sm[0][i-1];
		sm[1][i]=sm[1][i-1];
		if(s[i]==s[i-1])sm[s[i]-'0'][i]++;
	}
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		cout<<max(sm[1][r]-sm[1][l],sm[0][r]-sm[0][l])+1<<'\n';
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}