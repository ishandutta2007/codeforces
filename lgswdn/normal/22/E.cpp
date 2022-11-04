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

const int N=1e6+9;
int n,rt,in[N],to[N],f[N];
bool vst[N];
vi lf[N],l,r;
vp ans;

void dfs(int u) {
	vst[u]=1;
	if(vst[to[u]]&&!f[to[u]]) f[u]=u;
	else if(!vst[to[u]]) dfs(to[u]), f[u]=f[to[u]];
	else f[u]=f[to[u]];
}

int main() {
	n=read();
	rep(i,1,n) to[i]=read(), in[to[i]]++;
	rep(i,1,n) if(!vst[i]) dfs(i);
	rep(i,1,n) if(in[i]==0) lf[f[i]].emplace_back(i);
	int cnt=0,msz=0;
	rep(i,1,n) if(f[i]==i) {
		cnt++, msz=max(msz,(int)lf[i].size());
		if(!lf[i].size()) l.emplace_back(i);
		else l.emplace_back(lf[i][0]);
		r.emplace_back(i);
		for(int j=1;j<(int)lf[i].size();j++) ans.emplace_back(pii(i,lf[i][j]));
	}
	if(cnt==1&&msz==0) return puts("0"), 0;
	rep(i,0,cnt-1) ans.emplace_back(pii(r[i],l[(i+1)%cnt]));
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}