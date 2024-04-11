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
int T,n,q,a[100005];long long s[100005];set<long long>st;
inline void solve(int l,int r)
{
	if(l>r) return;
	int qwq=(a[r]+a[l])>>1,id=upper_bound(a+l,a+r+1,qwq)-a-1;
	if(id==r&&a[id]>qwq) id--;
	st.insert(s[r]-s[l-1]);
	if(l^r&&a[l]^a[r]) solve(l,id),solve(id+1,r);
}
int main()
{
	for(read(T);T--;)
	{
		read(n),read(q),st.clear();
		for(int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		solve(1,n);
		for(int x;q--;) read(x),puts(st.count(x)?"Yes":"No");
	}
	return 0;
}