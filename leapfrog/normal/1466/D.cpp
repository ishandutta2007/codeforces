//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;ll r[100005];pair<int,int>v[100005];
int main()
{
	for(read(T);T--;)
	{
		read(n),r[n-1]=0;for(int i=1;i<=n;i++) read(v[i].first),v[i].second=-1;
		for(int i=1,x,y;i<n;i++) read(x),read(y),v[x].second++,v[y].second++;
		sort(v+1,v+n+1);for(int i=1;i<=n;i++) r[n-1]+=1ll*(v[i].second+1)*v[i].first;
		for(int i=n-2,cnt=1;i;i--)
		{
			while(!v[cnt].second) cnt++;
			r[i]=r[i+1]-v[cnt].first,v[cnt].second--;
		}
		for(int i=1;i<n;i++) printf("%lld%c",r[i],i==n-1?'\n':' ');
	}
	return 0;
}