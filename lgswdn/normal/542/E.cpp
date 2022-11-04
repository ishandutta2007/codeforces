#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N],id[N],cnt,mx[N],ans;
vector<int>e[N];
bool vst[N];

int bfs(int s,int tag,int ret=0) {
	queue<int>q; q.push(s);
	rep(i,1,n) d[i]=n+1; d[s]=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		ret=max(ret,d[u]), id[u]=tag;
		for(auto v:e[u]) {
			if(d[u]==d[v]) return -1;
			if(d[v]>d[u]+1)  d[v]=d[u]+1, q.push(v);
		}
	}
	return ret;
}

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].push_back(v), e[v].push_back(u);
	}
	rep(i,1,n) {
		if(!id[i]) id[i]=++cnt;
		int res=bfs(i,id[i]);
		if(res==-1) return puts("-1"), 0;
		mx[id[i]]=max(mx[id[i]],res);
	} 
	rep(i,1,cnt) ans+=mx[i];
	printf("%d\n",ans);
	return 0;
}