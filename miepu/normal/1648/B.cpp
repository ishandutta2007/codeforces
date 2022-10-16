#include<bits/stdc++.h>
#define int long long
const int N=2000005;
using namespace std;

int sum[N],a[N];
int n,m;

int S(int l,int r){
	return sum[r]-sum[l-1];
}

void solve(){

	cin>>n>>m;
	int ct=0;
	map<int,int> vis;
	for(int i=1;i<=m+m;i++)sum[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]])continue;
		ct++;
		vis[a[i]]=1;
		sum[a[i]]++;
	}
	for(int i=1;i<=m+m;i++)sum[i]+=sum[i-1];
	int res=0;
	for(int i=1;i<=m;i++){
		if(!S(i,i))continue;
		for(int j=0,k=0;j<=m;j+=i,k++)
			if(S(k,k))
				res+=S(j,j+i-1);
	}
	if(res==ct*(ct+1)/2) cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
}

main(){
		ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}