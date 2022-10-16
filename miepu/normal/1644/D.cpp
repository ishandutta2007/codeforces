#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=998244353;
using namespace std;

int n,m,k,q;
int x[N],y[N];
int fn[N],fm[N];

void solve(){
	cin>>n>>m>>k>>q;
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	int cn=0,cm=0;
	int res=1;
	for(int i=q;i>=1;i--){
		if(cn==n||cm==m)continue;
		int fl=1;
		if(!fn[x[i]])cn++,fn[x[i]]=1,fl=k;
		if(!fm[y[i]])cm++,fm[y[i]]=1,fl=k;
		res=res*fl%mod;
	}
	for(int i=q;i>=1;i--)
		fn[x[i]]=fm[y[i]]=0;
	cout<<res<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}