#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<bitset>
#include<cmath>
#define fi first
#define se second
using namespace std;
const int MAXN=3010;
int n,x[MAXN],y[MAXN],tot;
pair<double,pair<int,int> > P[MAXN*MAXN/2];
bitset<MAXN> B[MAXN],X;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			++tot;
			P[tot].fi=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
			P[tot].se.fi=i,P[tot].se.se=j;
		}
	sort(P+1,P+tot+1);
	reverse(P+1,P+tot+1);
	for(int i=1;i<=tot;i++)
	{
		X=B[P[i].se.fi]&B[P[i].se.se];
		if(X.count()) {printf("%.010lf\n",P[i].fi/2);return 0;}
		B[P[i].se.fi][P[i].se.se]=1;
		B[P[i].se.se][P[i].se.fi]=1;
	}
	return 0;
}