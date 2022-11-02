#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read() {
	int x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if(f)x=-x; return x;
}
const int maxn=1e5+5;
priority_queue<int,vector<int>,greater<int> > q;
vector<int>e[maxn];
int x,y,n,m,vis[maxn];
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		printf("%d ",x);
		for(auto i:e[x])
			if(!vis[i])q.push(i),vis[i]=1;
	}
	return 0;
}