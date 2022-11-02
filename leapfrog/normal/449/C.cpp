#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
//}}}
const int N=100005;
int pr[N],pc;char pv[N];//prinit{{{
inline void prinit(int n=N-1)
{
	pv[1]=1;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++) {pv[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}
}//}}}//
int n;char vs[N];vector<pair<int,int> >rs;
int main()
{
	read(n),prinit();
	for(int z=pc,x=pr[z];z>=1;x=pr[--z])
	{
		vector<int>a;for(int i=x;i<=n;i+=x) if(!vs[i]) a.push_back(i);
		if(a.size()&1) swap(a[1],a[a.size()-1]),a.pop_back();
		for(size_t i=1;i<a.size();i+=2) rs.push_back(make_pair(a[i-1],a[i])),vs[a[i-1]]=vs[a[i]]=1;
	}printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d %d\n",x.first,x.second);
	return 0;
}