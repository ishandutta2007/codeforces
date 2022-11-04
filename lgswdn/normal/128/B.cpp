#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9,inf=1e6;
typedef long long ll;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

char str[N];
int n,k,s[N],anss;

int ch[N][29],st[N],len[N]={inf},lk[N],tot=1,rem,now=1,sz;
int newn(int s,int l) {return len[++tot]=l,st[tot]=s,lk[tot]=1,tot;}
void extend(int x) {
	rem++,sz++; int last=1;
	while(rem) {
		while(rem>len[ch[now][s[sz-rem+1]]])
			rem-=len[now=ch[now][s[sz-rem+1]]];
		int &v=ch[now][s[sz-rem+1]], c=s[st[v]+rem-1];
		if(x==c||!v) {
			lk[last]=now, last=now;
			if(!v) v=newn(sz-rem+1,inf);
			else break;
		} else {
			int u=newn(st[v],rem-1);
			ch[u][x]=newn(sz,inf), ch[u][c]=v;
			st[v]+=rem-1, len[v]-=rem-1;
			lk[last]=v=u, last=u;
		}
		(now==1?rem--:now=lk[now]);
	}
}
ll f[N],g[N];
void dfs1(int u) {
	bool leaf=1;
	rep(i,0,26) if(ch[u][i]) {
		dfs1(ch[u][i]);
		f[u]+=f[ch[u][i]];
		g[u]+=f[ch[u][i]]*(len[ch[u][i]]-1)+g[ch[u][i]];
		leaf=0;
	}
	if(leaf) f[u]=1;
	g[u]+=f[u];
	//cout<<u<<" "<<f[u]<<" "<<g[u]<<endl; 
}
void dfs2(int u,int k) {
	//cout<<endl<<u<<" "<<k<<endl;
	if(u!=1) rep(j,st[u],st[u]+len[u]-1) {
		if(k<=0) return;
		putchar('a'+s[j]-1),k-=f[u];
	}
	rep(i,(u==1?1:0),26) if(ch[u][i]) {
		if(k<=g[ch[u][i]]+f[ch[u][i]]*(len[ch[u][i]]-1)) {
			dfs2(ch[u][i],k);
			return;
		}
		k-=g[ch[u][i]]+f[ch[u][i]]*(len[ch[u][i]]-1);
	}
}

int main() {
	scanf("%s%d",str+1,&k); n=strlen(str+1);
	if(k>1ll*n*(n+1)/2) return puts("No such line."), 0;
	rep(i,1,n) s[i]=str[i]-'a'+1; s[++n]=0;
	rep(i,1,n) extend(s[i]);
	rep(i,1,tot) if(len[i]>n) len[i]=n-st[i];
	dfs1(1);
	dfs2(1,k);
	return 0;
}