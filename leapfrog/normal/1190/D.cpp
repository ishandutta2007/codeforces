//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,xt,yt,X[200005],Y[200005],tn[200005],ut,T[200005];
char vs[200005];vector<int>v[200005];ll rs=0;
inline void add(int x,int w) {for(;x<=xt;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline int q(int l,int r) {return qry(r)-qry(l-1);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(X[i]),read(Y[i]);
	tn[ut=1]=0;for(int i=1;i<=n;i++) tn[++ut]=X[i];
	sort(tn+1,tn+ut+1),xt=ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) X[i]=lower_bound(tn+1,tn+ut+1,X[i])-tn;
	tn[ut=1]=0;for(int i=1;i<=n;i++) tn[++ut]=Y[i];
	sort(tn+1,tn+ut+1),yt=ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) Y[i]=lower_bound(tn+1,tn+ut+1,Y[i])-tn;
	for(int i=1;i<=yt;i++) v[i].push_back(1);
	for(int i=1;i<=n;i++) v[Y[i]].push_back(X[i]);
	for(int i=1;i<=yt;i++) v[i].push_back(xt+1);
	for(int i=yt;i>=1;i--)
	{
		sort(v[i].begin(),v[i].end());
		//{for(auto x:v[i]) printf("%d ",x);putchar('\n');}
		for(int j=1;j<(int)v[i].size()-1;j++)
		{
			if(!vs[v[i][j]]) add(v[i][j],1),vs[v[i][j]]=1;
			rs+=1ll*q(1,v[i][j])*q(v[i][j],v[i][j+1]-1);
			//printf("%d,%d : %d*%d\n",i,v[i][j],q(1,v[i][j]),q(v[i][j],v[i][j+1]-1));
		}
	}
	return printf("%lld\n",rs),0;
}