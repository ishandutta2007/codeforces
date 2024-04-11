//Coded by leapfrog on 2021.11.05 {{{
//
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
const int N=300005;vector<pair<int,int> >v[N];
int n,m,ln[N],*a[N],buf[N<<1],pos[N],tn[N];
inline void solve()
{
	read(n,m),a[1]=buf;int lim=0;
	for(int i=1;i<=m;i++)
	{
		read(ln[i]),a[i+1]=a[i]+ln[i],lim+=ln[i];
		for(int j=1;j<=ln[i];j++) read(a[i][j]);
	}lim=sqrt(n);
	for(int i=1;i<=m;i++) if(ln[i]>lim)
	{
		for(int j=1;j<=n;j++) pos[j]=0;
		for(int j=1;j<=ln[i];j++) pos[a[i][j]]=j;
		for(int j=1;j<=m;j++) if(i^j)
		{
			int mx=0,nw=0;
			for(int k=ln[j];k>=1;k--)
			{
				if(!pos[a[j][k]]) continue;
				if(pos[a[j][k]]>mx) nw=mx=pos[a[j][k]];
				else if(pos[a[j][k]]!=nw-1) return puts("Human"),void();else nw--;
			}
		}
	}
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=m;i++) if(ln[i]<=lim)
	{
		for(int l=1;l<ln[i];l++) for(int r=l+1;r<=ln[i];r++)
			v[a[i][l]].push_back(make_pair(a[i][r],a[i][r-1]));
	}
	for(int i=1;i<=n;i++) tn[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(auto x:v[i]) if(!tn[x.first]) tn[x.first]=x.second;
			else if(tn[x.first]!=x.second) return puts("Human"),void();
		for(auto x:v[i]) tn[x.first]=0;
	}
	puts("Robot");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}