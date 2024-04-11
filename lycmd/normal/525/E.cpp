#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=26;
int n,m,s,ans,a[N],fac[N];
unordered_map<int,int>cnt[N];
void dfs1(int x,int y,int k){
	if(y>s||k>m)
	    return;
	if(x>n/2){
	    cnt[k][y]++;
	    return;
	}
	dfs1(x+1,y,k);
	dfs1(x+1,y+a[x],k);
	if(a[x]<=20)
	    dfs1(x+1,y+fac[a[x]],k+1);
}
void dfs2(int x,int y,int k){
	if(y>s||k>m)
	    return;
	if(x>n){
        for(int i=0;i<=m-k;i++)ans+=cnt[i][s-y];
        return;
	}
	dfs2(x+1,y,k);
	dfs2(x+1,y+a[x],k);
	if(a[x]<=20)
	    dfs2(x+1,y+fac[a[x]],k+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=0;i<N;i++)
		fac[i]=i?fac[i-1]*i:1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs1(1,0,0),dfs2(n/2+1,0,0);
	cout<<ans<<"\n";
}