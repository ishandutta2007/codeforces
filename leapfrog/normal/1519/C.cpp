//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,id[200005],a[200005],it;vector<ll>v[200005];set<int>st;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),v[i].clear();
	for(int i=1,w;i<=n;i++) read(w),v[a[i]].push_back(w);
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),greater<int>());
	for(int i=1;i<=n;i++) for(int j=1;j<(int)v[i].size();j++) v[i][j]+=v[i][j-1];
	st.clear();for(int i=1;i<=n;i++) st.insert(i);
	for(int k=1;k<=n;k++)
	{
		it=0;ll res=0;for(auto x:st)
		{
			if(k>(int)v[x].size()) {id[++it]=x;continue;}
			res+=v[x][(int)(v[x].size())/k*k-1];
		}
		printf("%lld ",res);for(int i=1;i<=it;i++) st.erase(id[i]);
	}
	putchar('\n');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}