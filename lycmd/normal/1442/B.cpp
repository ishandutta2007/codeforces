#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353,N=233333;
int T,n,m,a[N],b[N],pos[N],vis[N];
signed main(){
    ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],vis[pos[a[i]]=i]=0;
		for(int i=1;i<=m;i++)cin>>b[i];
		int ans=1;
		for(int i=m;i>=1&&ans;vis[b[i]]=1,i--){
			int k=0;
			k+=pos[b[i]]!=1&&!vis[a[pos[b[i]]-1]];
			k+=pos[b[i]]!=n&&!vis[a[pos[b[i]]+1]];
			ans=ans*k%MOD;
		}
		cout<<ans<<"\n";
	}
}