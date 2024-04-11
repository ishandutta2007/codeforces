#include<bits/stdc++.h>
#define ll long long
#define N 300010
#define mid ((l+r)>>1)
using namespace std;
struct fck
{
	int a,b,id,tg;
	bool operator<(const fck&x) const
	{
		return b<x.b;
	}
}e[N];int tp[2],ans,f[N],to[2][N],pp[2];

int yp[N],x[N],y[N];
int main()
{
	int n,i,ae=0,be=0;scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&e[i].a,&e[i].b);
		if (e[i].a<e[i].b) ae++;
		else be++,swap(e[i].a,e[i].b),e[i].tg=1;e[i].id=i;
	}
	sort(e+1,e+n+1);
	if (ae>be)
	{
		cout<<ae<<endl;
		for (i=n;i;i--) if (!e[i].tg) cout<<e[i].id<<' ';
	}
	else
	{
		cout<<be<<endl;
		for (i=1;i<=n;i++) if (e[i].tg) cout<<e[i].id<<' ';
	}
}