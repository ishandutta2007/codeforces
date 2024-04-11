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
int n,D,X,a[100005],b[100005],rs[200005],id[100005];vector<int>vc;
inline int rnd() {return X=(X*37ll+10007)%1000000007;}
inline void init()
{
	for(int i=0;i<n;i++) a[i]=i+1;
	for(int i=0;i<n;i++) swap(a[i],a[rnd()%(i+1)]);
	for(int i=0;i<n;i++) b[i]=i<D;
	for(int i=0;i<n;i++) swap(b[i],b[rnd()%(i+1)]);
	//for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');
	//for(int i=0;i<n;i++) printf("%d%c",b[i],i==n-1?'\n':' ');
}
int main()
{
	read(n,D,X),init();const int M=sqrt(n);
	for(int i=0;i<n;i++) if(b[i]) vc.push_back(i);
	for(int i=0;i<n;i++) id[a[i]]=i;
	for(int i=max(n-M,0);i<=n;i++) for(auto j:vc) rs[id[i]+j]=i;
	for(int i=0;i<n;i++) if(!rs[i])
		{for(auto j:vc) if(j>i) break;else rs[i]=max(rs[i],a[i-j]);}
	for(int i=0;i<n;i++) printf("%d\n",rs[i]);
	return 0;
}