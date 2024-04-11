#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;

string s;
int n;
string S[N];

void solve(){
	cin>>n;
	cin>>s,s='0'+s;
	int mx=(1<<n)-1;
	for(int i=mx;i>=mx>>1;i--)
		S[i]=s[i];
	int res=1;
	for(int i=(mx>>1);i>=1;i--){
		if(S[i<<1]!=S[i<<1|1])
			res=res*2%mod;
		S[i]=min(S[i<<1]+s[i]+S[i<<1|1],S[i<<1|1]+s[i]+S[i<<1]);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}