//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,K,a[500005],b[500005];priority_queue<pair<int,int> >q;
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	long long l=0,r=2e9,md;for(int i=1;i<=n;i++) read(b[i]);
	while(l<=r)
	{
		md=(l+r)>>1;long long s=0;int cnt=0;
		for(int i=1;i<=n;i++)
		{
			q.push(make_pair(-a[i],0));
			int tmp=b[i]-md-q.top().first;
			if(tmp<0) s+=tmp,q.pop(),q.push(make_pair(b[i]-md,1));
		}
		while(!q.empty()) cnt+=q.top().second,q.pop();
		if(cnt==K) return printf("%lld\n",s+1ll*K*md),0;
		if(cnt<K) l=md+1;else r=md-1;
	}
}