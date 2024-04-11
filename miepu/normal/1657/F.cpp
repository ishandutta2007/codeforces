#include<bits/stdc++.h>
const int N=16000060,M=800050;
using namespace std;
using vi = basic_string<int> ; 

struct edge{
	int to,nx;
}e[N<<2];int hd[N],S;
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
void add(int fr,int to){
	e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,m;
int dfn[N],low[N],ins[N],cnt,res;
stack<int> s;
int bel[N];

void tarjan(int k){
	dfn[k]=low[k]=++cnt;
	s.push(k),ins[k]=1;
	fore(k)
		if(!dfn[_to])tarjan(_to),low[k]=min(low[k],low[_to]);
		else if(ins[_to])low[k]=min(low[k],dfn[_to]);
	if(dfn[k]==low[k]){
		++res;
		int pr=-1;
		while(pr!=k){
			pr=s.top();
			bel[pr]=res;
			ins[pr]=0;
			s.pop();
		}
	}
}

int sz;

void lim(int a,int b,int c,int d){
	add(a+b*sz,c+!d*sz);
	add(c+d*sz,a+!b*sz);
}

vector<int> ed[M];
int f[M],dp[M];
int id[M][26],CNT;

void dfs(int k,int fa){
	f[k]=fa;
	dp[k]=dp[fa]+1;
	for(auto u:ed[k])if(u!=fa)
		dfs(u,k);
}

vi getpath(int u,int v){
	vi a,b;
	while(u!=v){
		if(dp[u]<dp[v]){
			b+=v;
			v=f[v];	
		}else{
			a+=u;
			u=f[u];
		}
	}
	reverse(b.begin(),b.end());
	return a+u+b;
}

void solve(){
	cin>>n>>m;
	sz=N/2;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int x,y;string s;
		cin>>x>>y>>s;
		auto pa=getpath(x,y);
		int l=s.size();
		int p=++CNT;
		for(int i=0;i<l;i++){
			int k=pa[i];
			int ch=s[i]-'a';
			if(!id[k][ch])id[k][ch]=++CNT;
			lim(id[k][ch],1,p,0);
		}
		reverse(s.begin(),s.end());
		int q=++CNT;
		for(int i=0;i<l;i++){
			int k=pa[i];
			int ch=s[i]-'a';
			if(!id[k][ch])id[k][ch]=++CNT;
			lim(id[k][ch],1,q,0);
		}
		lim(p,1,q,1);
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			if(id[i][j])
				for(int k=j+1;k<26;k++)
					if(id[i][k])
						lim(id[i][j],0,id[i][k],0);
	for(int i=1;i<=CNT+sz;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=CNT;i++)
		if(bel[i]==bel[i+sz])
			cout<<"NO"<<endl,exit(0);
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){
		int fl=0;
		for(int j=0;j<26;j++)
			if(id[i][j]){
				if(bel[id[i][j]]<bel[id[i][j]+sz])
					fl=1,cout<<(char)(j+'a');
			}
		if(!fl)cout<<'a';
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}