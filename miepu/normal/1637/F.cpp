#include<bits/stdc++.h>
#define int long long
const int N=1000005,inf=1e18;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S,in[to]++;
}

int n,rt=1;
int h[N],g[N],mx[N];

void dfs(int k,int fa){
	int mx1=0,mx2=0;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		mx[k]=max(mx[k],mx[_to]);
		g[k]+=g[_to]; 
		if(mx[_to]>mx1)mx2=mx1,mx1=mx[_to];
		else if(mx[_to]>mx2) mx2=mx[_to];
	}
	if(k==rt){
		g[k]+=max(h[k]-mx1,0ll)+max(h[k]-mx2,0ll);
	}
	else 
		if(mx[k]<h[k])g[k]+=h[k]-mx[k],mx[k]=h[k];
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i],rt=h[rt]>h[i]?rt:i;
	if(n==2)cout<<max(h[1],h[2])*2<<endl,exit(0);
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x); 
	}
	dfs(rt,0);
	cout<<g[rt]<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}