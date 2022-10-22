#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 25
#define Q 300005
#define ll long long
int n,m,q[Q],lg[N],nw[N],d[N][M];map<int,bool> vs;map<int,ll> ans;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int qGcd(int l,int r) {int t=lg[r-l+1];return gcd(d[l][t],d[r-(1<<t)+1][t]);}
int main()
{
	scanf("%d",&n);for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i) scanf("%d",&d[i][0]);
	for(int i=1;i<=lg[n];++i) for(int j=1;j+(1<<i)-1<=n;++j)
		d[j][i]=gcd(d[j][i-1],d[j+(1<<i-1)][i-1]);
	scanf("%d",&m);for(int i=1;i<=m;++i) scanf("%d",&q[i]),vs[q[i]]=1;
	for(int i=1,L,R,t1,t2,tmp1,tmp2;i<=n;++i)
	{
		t1=i;t2=d[i][0];
		while(1)
		{
			L=t1+1;R=n;tmp1=t1;t1=n+1;
			while(L<=R)
			{
				int mid=L+R>>1,x=qGcd(i,mid);
				if(x==t2) L=mid+1;else t1=mid,tmp2=x,R=mid-1;
			}if(vs[t2]) ans[t2]+=t1-tmp1;t2=tmp2;if(t1>n) break;
		}
	}for(int i=1;i<=m;++i) printf("%lld\n",ans[q[i]]);return 0;
}