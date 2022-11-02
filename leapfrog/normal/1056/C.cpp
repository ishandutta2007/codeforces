//Coded by leapfrog on 2021.11.05 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=10005;
int n,m,tw[N],vs[N],vl[N];
priority_queue<pair<int,int> >q;
int main()
{
	read(n,m);for(int i=1;i<=n+n;i++) read(vl[i]);
	for(int i=1,x,y;i<=m;i++) read(x,y),tw[x]=y,tw[y]=x;
	int t;read(t);
	if(t&1)
	{
		for(int i=1;i<=n+n;i++) if(tw[i]&&!vs[i]&&!vs[tw[i]])
		{
			printf("%d\n",vl[tw[i]]>vl[i]?tw[i]:i),fflush(stdout);
			int w;read(w),vs[tw[i]]=vs[i]=1;
		}
		for(int i=1;i<=n+n;i++) if(!vs[i]) q.push(make_pair(vl[i],i));
		while(1)
		{
			while(!q.empty()&&vs[q.top().second]) q.pop();
			if(q.empty()) break;
			int x=q.top().second;printf("%d\n",x),fflush(stdout);
			int w;read(w),vs[w]=vs[x]=1;
		}
	}
	else
	{
		for(int i=1;i<=n+n;i++) q.push(make_pair(vl[i],i));
		char fg=0;
		while(!q.empty())
		{
			while(!q.empty()&&vs[q.top().second]) q.pop();
			if(q.empty()) break;
			int w;read(w),vs[w]=1;
			if(tw[w]&&!vs[tw[w]])
			{
				printf("%d\n",tw[w]),fflush(stdout),vs[tw[w]]=1;
				while(!q.empty()&&vs[q.top().second]) q.pop();
				if(q.empty()) break;else continue;
			}
			if(!fg)
			{
				fg=1;for(int i=1;i<=n+n;i++) if(tw[i]&&!vs[i]&&!vs[tw[i]])
				{
					printf("%d\n",vl[tw[i]]>vl[i]?tw[i]:i),fflush(stdout);
					int w;read(w),vs[tw[i]]=vs[i]=1;
				}
			}
			while(!q.empty()&&vs[q.top().second]) q.pop();
			if(q.empty()) break;
			int x=q.top().second;printf("%d\n",x),fflush(stdout),vs[x]=1;
		}
	}return 0;
}