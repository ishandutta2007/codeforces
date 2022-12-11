#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
const int N=1e5+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int head[N],next[N],to[N],w[N];
LL dis[N];int d[N];
vector<int>q[N*10];
bool vis[N];
bool in[N];
struct heap{ int k;LL dis; inline bool operator < (const heap &b) const { return dis>b.dis; } };
inline void dj(int n) {
	int i,k;
	priority_queue<heap>q;
	for (i=1;i<=n;i++) dis[i]=1LL<<60;
	q.push((heap){1,dis[1]=0});
	while (!q.empty()) {
		k=q.top().k;q.pop();
		vis[k]=true;
		for (i=head[k];i;i=next[i])
			if (dis[k]+w[i]<dis[to[i]])
				q.push((heap){to[i],dis[to[i]]=dis[k]+w[i]});
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n=gi(),m=gi(),Q=gi(),i,k,L,R,s=0;
	for (i=1;i<=m;i++) {
		next[i]=head[k=gi()],head[k]=i;
		to[i]=gi(),w[i]=gi();
	}
	dj(n);
	while (Q--)
		if (gi()==1) {
			k=gi();
			printf("%I64d\n",vis[k]?d[k]+dis[k]:-1);
		} else {
			for (k=gi();k--;) w[gi()]++,s++;
			for (i=1;i<=n;i++) d[i]=1<<30,vis[i]=false;
			q[d[1]=0].push_back(1);
			L=R=0;
			while (L<=R)
				if (!q[L].empty()) {
					k=q[L].back();q[L].pop_back();
					if (vis[k]) continue;
					vis[k]=true;
					for (i=head[k];i;i=next[i])
						if (dis[k]+d[k]+w[i]<dis[to[i]]+d[to[i]]) {
							d[to[i]]=dis[k]+d[k]+w[i]-dis[to[i]];
							if (d[to[i]]>s) continue;
							q[d[to[i]]].push_back(to[i]);
							L=min(L,d[to[i]]);
							R=max(R,d[to[i]]);
						}
				} else L++;
		}
	
	return 0;
}