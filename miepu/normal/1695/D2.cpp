#include<bits/stdc++.h>
const int N=2000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S,in[to]++;
}

int n,fl[N],na,ans=N;

void dfs(int k,int fa){
	int c=0;
	fore(k)if(_to!=fa)dfs(_to,k),c++,fl[k]+=(bool)fl[_to];
	na+=max(0,c-fl[k]-1),fl[k]+=max(0,c-fl[k]-1);
}

void solve(){
	for(int i=1;i<=n;i++)hd[i]=0,fl[i]=0,in[i]=0;S=0;ans=N;na=0;
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(in[i]>2){
			dfs(i,0);
			break;
		}
	if(na==0)cout<<1<<endl;
	else cout<<na<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
}