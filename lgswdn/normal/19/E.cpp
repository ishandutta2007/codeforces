#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e5+9;
int n,m,d[N],f[N],s[N],cnt;
bool vst[N],del[N],fs[N],evst[N];
vp e[N],t[N];

void dfs1(int u) {
	vst[u]=1;
	for(auto ed:e[u]) if(!evst[ed.se]) {
		int v=ed.fi, id=ed.se; evst[id]=1;
		if(!vst[v]) {
			d[v]=d[u]+1, t[u].emplace_back(pii(v,id));
			dfs1(v);
		} else {
			if((d[u]-d[v])%2==1) f[v]++, f[u]--;
			else f[v]--, f[u]++, cnt++, fs[id]=1;
		}
	}
}
void dfs2(int u) {
	s[u]+=f[u]; vst[u]=1;
	for(auto ed:t[u]) {
		int v=ed.fi, id=ed.se;
		dfs2(v);
		if(s[v]==cnt) del[id]=1;
		s[u]+=s[v];
	}
}

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].emplace_back(pii(v,i)), e[v].emplace_back(pii(u,i));
	}
	rep(i,1,n) if(!vst[i]) dfs1(i);
	if(cnt==0) {
		printf("%d\n",m);
		rep(i,1,m) printf("%d ",i);
		puts("");
		return 0;
	}
	rep(i,1,n) vst[i]=0;
	rep(i,1,n) if(!vst[i]) dfs2(i);
	vi ans;
	rep(i,1,m) {
		if(del[i]) ans.emplace_back(i);
		else if(cnt==1&&fs[i]) ans.emplace_back(i);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x); if(ans.size()) puts("");
	return 0;
}