//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
typedef bitset<1005> Bt;int n,s,D;Bt c[35];unordered_map<Bt,int>mn;
inline char operator<(Bt a,Bt b)
{
	for(int i=1;i<=1000;i++) if(a[i]^b[i]) return a[i]<b[i];
	return 0;
}
int main()
{
	read(n),read(s),read(D);int m=min(s,20);
	for(int i=1,k,x;i<=s;i++) {read(k);while(k--) read(x),c[i][x]=1;}
	for(int S=0,ct=0;S<(1<<m);S++,ct=0)
	{
		Bt b;for(int j=0;j<m;j++) if((S>>j)&1) b^=c[j+1],ct++;
		if(!mn.count(b)||mn[b]>ct) mn[b]=ct;
	}
	for(int i=1,k,x;i<=D;i++)
	{
		Bt b;read(k);while(k--) read(x),b[x]=1;
		int rs=1e9;for(int S=0;S<(1<<(s-m));S++)
		{
			Bt bt;int tt=0;
			for(int j=0;j<s-m;j++) if((S>>j)&1) bt^=c[j+m+1],tt++;
			bt^=b;if(mn.count(bt)) rs=min(rs,mn[bt]+tt);
		}
		if(rs==1000000000) puts("-1");else printf("%d\n",rs);
	}
	return 0;
}