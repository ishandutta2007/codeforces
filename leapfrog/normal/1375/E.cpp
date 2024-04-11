//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1005;vector<pair<int,int> >v;
pair<int,int>a[N];int n,tn[N],tt;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].first),a[i].second=i;
	for(int i=1;i<=n;i++)
	{
		tt=0;for(int j=i+1;j<=n;j++) if(a[j]<a[i]) tn[++tt]=j;
		sort(tn+1,tn+tt+1,[](int x,int y){return a[x]<a[y];});
		for(int j=tt;j>=1;j--) v.push_back(make_pair(i,tn[j])),swap(a[i],a[tn[j]]);
		//for(int j=1;j<=n;j++) printf("%d%c",a[j].first,j==n?'\n':' ');
	}printf("%d\n",(int)v.size());
	for(auto x:v) printf("%d %d\n",x.first,x.second);
	return 0;
}
//
//
// shift