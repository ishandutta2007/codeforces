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
int n,a[200005],b[200005],rp;map<int,int>mp;
inline int Get(int x) {if(mp[x]) return mp[x];else return mp[x]=++rp;}
int main()
{
	read(n);int res=1e9;
	for(int i=1,x,y;i<=n;i++)
	{
		read(x),read(y),x=Get(x),y=Get(y);
		a[x]++;if(x^y) b[y]++;
	}
	for(int i=1;i<=rp;i++) if(a[i]+b[i]>=((n+1)>>1)) res=min(res,min(b[i],((n+1)>>1)-a[i]));
	return printf("%d\n",res>100000?-1:max(res,0)),0;
}