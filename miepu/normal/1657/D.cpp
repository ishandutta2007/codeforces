#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int c[N],d[N],h[N];
int at[N],sh[N];

void solve(){
	int n,C;
	cin>>n>>C;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i]>>h[i];
		at[c[i]]=max(at[c[i]],d[i]*h[i]);
	}
	for(int i=1;i<=C;i++)
		for(int j=i;j<=C;j+=i)
			sh[j]=max(sh[j],at[i]*(j/i));
	for(int i=1;i<=C;i++)
		sh[i]=max(sh[i-1],sh[i]);
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		int nA=x*y;
		int t=upper_bound(sh+1,sh+1+C,nA)-sh;
		if(t>C){
			cout<<-1<<'\n';
			continue;
		}
		cout<<t<<'\n';
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}