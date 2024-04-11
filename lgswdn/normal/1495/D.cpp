#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=609,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N][N],cnt[N][N];
vector<int>e[N];

void bfs(int s) {
	queue<int>q; q.push(s);
	memset(d[s],0x3f,sizeof(d[s])); d[s][s]=0, cnt[s][s]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u])
			if(d[s][v]==inf) d[s][v]=d[s][u]+1, cnt[s][v]=cnt[s][u], cnt[s][v]=min(cnt[s][v],2ll), q.push(v);
			else if(d[s][v]==d[s][u]+1) cnt[s][v]+=cnt[s][u], cnt[s][v]=min(cnt[s][v],2ll);
	}
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].push_back(v), e[v].push_back(u);
	}
	rep(i,1,n) bfs(i);
	rep(x,1,n) {
		rep(y,1,n) {
			if(cnt[x][y]>1) putchar('0');
			else {
				int ans=1;
				rep(u,1,n) {
					if(d[x][u]+d[u][y]==d[x][y]) continue;
					int tot=0;
					for(auto v:e[u]) tot+=((d[x][v]+1==d[x][u])&&(d[y][v]+1==d[y][u]));
					ans=ans*tot%mod;
				}
				printf("%d",ans);
			}
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}