#include<bits/stdc++.h>
using namespace std;
#define re register
int a[110],l[110],q[310],f[310][2];
struct par{int l,r,a;}p[110];
inline bool cmp(const par&A,const par&B){return A.a<B.a;}
int main()
{
	re int n,n1;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d%d",&a[i],&l[i]),q[3*i-2]=a[i]-l[i],q[3*i-1]=a[i],q[3*i]=a[i]+l[i];
	sort(q+1,q+3*n+1);
	n1=unique(q+1,q+3*n+1)-q-1;
	for(re int i=1;i<=n;i++)
	{
		p[i].l=lower_bound(q+1,q+n1+1,a[i]-l[i])-q;
		p[i].r=lower_bound(q+1,q+n1+1,a[i]+l[i])-q;
		p[i].a=lower_bound(q+1,q+n1+1,a[i])-q;
	}
	sort(p+1,p+n+1,cmp);
	for(re int i=1;i<=n1;i++)
	{
		f[i+1][1]=max(max(f[i][0],f[i][1]),f[i+1][1]);
		for(re int j=1;j<=n;j++)if(p[j].a>i&&p[j].l<=i)
		{
			re int x=p[j].a;
			for(re int i1=1;i1<=n;i1++)if(i1!=j&&p[i1].a>=i&&p[i1].a<=x)x=max(x,p[i1].r);
			f[x][0]=max(f[x][0],f[i][1]+q[x]-q[i]);
			x=p[j].a;
			for(re int i1=1;i1<=n;i1++)if(i1!=j&&p[i1].a>i&&p[i1].a<=x)x=max(x,p[i1].r);
			f[x][0]=max(f[x][0],f[i][0]+q[x]-q[i]);
		}else if(p[j].a==i)
		{	
			re int x=p[j].r;
			for(re int i1=1;i1<=n;i1++)if(i1!=j&&p[i1].a>=i&&p[i1].a<=x)x=max(x,p[i1].r);
			f[x][1]=max(f[x][1],f[i][1]+q[x]-q[i]);
		}//printf("**%d %d %d %d\n",i,q[i],f[i][0],f[i][1]);
	}
	printf("%d\n",max(f[n1][0],f[n1][1]));
}