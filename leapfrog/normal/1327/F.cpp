//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=998244353,N=500005;
int n,K,Q,cf[N],mp[N],dp[N];vector<pair<int,int> >v[N];
inline int solve(int wh)
{
	dp[0]=1;for(int i=1;i<=n;i++) cf[i]=dp[i]=0;
	for(int i=1;i<=n;i++) for(auto j:v[i]) if((j.second>>wh)&1) cf[j.first]++,cf[i+1]--;
	for(int i=1;i<=n;i++) cf[i]+=cf[i-1];
	int it1=0,sm1=0,sm2=1,tt=0;for(int i=1;i<=n;i++)
	{
		if(cf[i]) mp[i]=tt;else mp[i]=++tt;
		if(!cf[i]) sm2=((dp[tt]=(sm2-sm1+P)%P)+sm2)%P;
		for(auto w:v[i]) if(!((w.second>>wh)&1))
		{
			int j=w.first;if(mp[j]==mp[i]&&cf[j]&&cf[i]) return 0;
			while(it1<mp[j]+!!cf[j]) sm1=(sm1+dp[it1++])%P;
		}
	}
	int rs=0;for(int i=it1;i<=tt;i++) rs=(rs+dp[i])%P;
	return rs;
}
int main()
{
	read(n),read(K),read(Q);int res=1;
	for(int i=1,l,r,w;i<=Q;i++) read(l),read(r),read(w),v[r].push_back(make_pair(l,w));
	for(int i=0;i<K&&res;i++) res=1ll*res*solve(i)%P;
	return printf("%d\n",res),0;
}