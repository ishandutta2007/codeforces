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
int n,a[100005];char vv[2000005];set<int>st;
inline void E(int x) {if(st.find(x)!=st.end()) st.erase(x);}
inline void ers(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0)
	{
		if(!vv[i]) {vv[i]=1;for(int j=i;j<=2000000;j+=i) E(j);}
		while(x%i==0) x/=i;
	}
	if(!vv[x]) {vv[x]=1;for(int j=x;j<=2000000;j+=x) E(j);}
}
int main()
{
	vv[1]=1;for(int i=2;i<=2000000;i++) st.insert(i);
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	char fg=0;for(int i=1;i<=n;ers(a[i++])) if(fg) a[i]=*st.begin();
		else if(!st.count(a[i])) a[i]=*st.lower_bound(a[i]),fg=1;
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}