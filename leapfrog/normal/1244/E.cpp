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
int n;ll K;map<int,int>mp;
int main()
{
	read(n),read(K);for(int i=1,x;i<=n;i++) read(x),mp[x]++;
	int _=1;while(1>_<1)
	{
		if((int)mp.size()==1) return puts("0"),0;
		pair<int,int>x=*mp.begin(),y=*mp.rbegin(),z=*++mp.begin();
		//printf("%lld\n",K);for(auto x:mp) printf("<%d,%d>",x.first,x.second);putchar('\n');
		if(x.second>y.second)
		{
			mp.erase(y.first),z=*mp.rbegin();ll vl=1ll*(y.first-z.first)*y.second;
			if(K<=vl) return printf("%lld\n",y.first-x.first-(K/y.second)),0;
			K-=vl,mp.erase(--mp.end()),z.second+=y.second,mp.insert(z);
		}
		else
		{
			mp.erase(x.first),z=*mp.begin();ll vl=1ll*(z.first-x.first)*x.second;
			if(K<=vl) return printf("%lld\n",y.first-x.first-(K/x.second)),0;
			K-=vl,mp.erase(mp.begin()),z.second+=x.second,mp.insert(z);
		}
	}
	return 0;
}