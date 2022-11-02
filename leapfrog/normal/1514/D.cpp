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
const int N=300005,sz=708;int n,m,a[N],L[N],R[N],bl[N],blc;
int tn[N],ut,wh[N],mx[sz+5][sz+5],cn[N];vector<int>v[N];
inline int solve(int l,int x) {if(x<=(l+1)/2) return 1;else return l-2*(l-x);}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),tn[++ut]=a[i],bl[i]=(i-1)/sz+1;
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;for(int i=1;i<=n;i++)
		v[a[i]=lower_bound(tn+1,tn+ut+1,a[i])-tn].push_back(i),wh[i]=v[a[i]].size()-1;
	for(int i=1;i<=n+1;i++) if(bl[i-1]^bl[i]) {R[blc]=i-1;if(i^(n+1)) L[++blc]=i;}
	for(int i=1;i<=blc;i++,memset(cn,0,sizeof(cn))) for(int j=i;j<=blc;j++)
		{int &nw=(mx[i][j]=mx[i][j-1]);for(int k=L[j];k<=R[j];k++) nw=max(nw,++cn[a[k]]);}
	for(int l,r,rs=0;m--;printf("%d\n",solve(r-l+1,rs)))
	{
		read(l),read(r),rs=0;
		if(bl[l]==bl[r])
		{
			for(int i=l;i<=r;i++) rs=max(rs,++cn[a[i]]);
			for(int i=l;i<=r;i++) cn[a[i]]=0;
			continue;
		}
		rs=mx[bl[l]+1][bl[r]-1];
		for(int i=l;i<=R[bl[l]];i++) {int nw=wh[i];while(nw+rs<(int)v[a[i]].size()&&v[a[i]][nw+rs]<=r) rs++;}
		for(int i=L[bl[r]];i<=r;i++) {int nw=wh[i];while(nw-rs>=0&&v[a[i]][nw-rs]>=l) rs++;}
	}
	return 0;
}