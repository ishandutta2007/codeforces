//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];
int n,m,et,head[505],dag[505],tmp[505];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char topsort()
{
	queue<int>q;int cnt=0;for(int i=1;i<=n;i++) if(!dag[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();++cnt;
		for(int i=head[x];i;i=e[i].nxt) if(!--dag[e[i].to]) q.push(e[i].to);
	}
	return cnt==n;
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),tmp[y]++;
	memcpy(dag,tmp,sizeof(dag)),dag[3]--;
	for(int i=1;i<=n;i++) if(tmp[i])
	{
		memcpy(dag,tmp,sizeof(tmp)),dag[i]--;
		if(topsort()) return puts("YES"),0;
	}
	return puts("NO"),0;
}