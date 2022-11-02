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
int n,a[2005];vector<int>v1,v0;vector<pair<int,int> >e;
inline void adde(int x,int y) {e.push_back(make_pair(min(x,y),max(x,y)));}
int main()
{
	read(n),printf("? %d\n",1),fflush(stdout);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) if(a[i]==1) adde(i,1);
	for(int i=2;i<=n;i++) (a[i]&1?v1:v0).push_back(i);
	if(v1.size()>v0.size()) swap(v1,v0);
	for(auto x:v1)
	{
		printf("? %d\n",x),fflush(stdout);
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=2;i<=n;i++) if(a[i]==1) adde(x,i);
	}
	puts("!"),sort(e.begin(),e.end());
	for(auto x:e) printf("%d %d\n",x.first,x.second);
	return 0;
}