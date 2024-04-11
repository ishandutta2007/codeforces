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
int n,l[200005],r[200005],lst,tn[400005],cf[400005],tag;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(l[i]),read(r[i]),tn[++lst]=l[i],tn[++lst]=r[i];
	sort(tn+1,tn+lst+1),lst=unique(tn+1,tn+lst+1)-tn-1;
	for(int i=1;i<=n;i++) l[i]=lower_bound(tn+1,tn+lst+1,l[i])-tn,r[i]=lower_bound(tn+1,tn+lst+1,r[i])-tn;
	for(int i=1;i<=n;i++) cf[l[i]]++,cf[r[i]+1]--;
	for(int i=1;i<=lst;i++) cf[i]+=cf[i-1],tag|=cf[i]>2;
	return puts(tag?"NO":"YES"),0;
}