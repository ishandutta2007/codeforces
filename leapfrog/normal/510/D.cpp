//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,l[305],c[305];map<int,int>d;
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	read(n),d[0]=0,q.push(make_pair(0,0));
	for(int i=1;i<=n;i++) read(l[i]);
	for(int i=1;i<=n;i++) read(c[i]);
	while(!q.empty())
	{
		int x=q.top().second,w=q.top().first;q.pop();if(w!=d[x]) continue;
		for(int i=1;i<=n;i++) if(!d.count(gcd(x,l[i]))||d[gcd(x,l[i])]>w+c[i])
			d[gcd(x,l[i])]=w+c[i],q.push(make_pair(w+c[i],gcd(x,l[i])));
	}
	if(d.count(1)) return printf("%d\n",d[1]),0;else return puts("-1"),0;
}