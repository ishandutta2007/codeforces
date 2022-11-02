//
//
#include<bits/stdc++.h>
using namespace std;const int m=6;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[100005],b[38],mx=2e9,cnt=0;pair<int,int>mp[1000005];char q[100005];
int main()
{
	for(int i=1;i<=m;i++) read(b[i]);
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mp[++cnt]=make_pair(b[j]-a[i],i);
	sort(mp+1,mp+cnt+1);int le=1,zkak=0,res=1e9;
	for(int i=1;i<=cnt;i++)
	{
		if(!q[mp[i].second]) zkak++;
		++q[mp[i].second];
		while(q[mp[le].second]>1) q[mp[le].second]--,++le;
		if(zkak==n) res=min(res,mp[i].first-mp[le].first);
	}
	return printf("%d\n",res),0;
}