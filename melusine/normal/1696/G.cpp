#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct jz
{
	double a[4][4];
};
struct jz operator*(struct jz x,struct jz y)
{
	struct jz ans;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			ans.a[i][j]=-1121131433448687LL;
			for(int k=1;k<=3;k++)
			{
				ans.a[i][j]=max(ans.a[i][j],x.a[i][k]+y.a[k][j]); 
			}
		}
	}
	return ans;
}
struct tree
{
	int l,r;
	struct jz sth;
}a[800004];
int tx,ty;
struct jz findjz(int now)
{
	struct jz ans;
	ans.a[1][1]=ans.a[1][2]=ans.a[2][1]=-1121131433448687LL;
	ans.a[1][3]=0;
	ans.a[2][2]=now*(1.0/(tx+ty));
	ans.a[2][3]=0;
	ans.a[3][1]=now*(1.0/ty);
	ans.a[3][2]=now*(1.0/(tx+ty));
	ans.a[3][3]=0; 
	return ans;
}
int qz[200005];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].sth=findjz(qz[l]);
		//printf("%.9lf\n",a[k].sth.a[3][1]);
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	a[k].sth=a[k<<1].sth*a[k<<1|1].sth;
	//printf("%d %d %.9lf\n",a[k].l,a[k].r,a[k].sth.a[3][1]);
}
void change(int x,int k,int y)
{
	if(a[k].l==a[k].r)
	{
		a[k].sth=findjz(y);
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	a[k].sth=a[k<<1].sth*a[k<<1|1].sth;
}
struct jz query(int l,int r,int k)
{
	if(a[k].l>=l&&a[k].r<=r)return a[k].sth;
	if(r<=a[k<<1].r)return query(l,r,k<<1);
	if(l>=a[k<<1|1].l)return query(l,r,k<<1|1);
	struct jz la=query(l,r,k<<1),ra=query(l,r,k<<1|1);
	return la*ra; 
}
signed main()
{
	int n,q,opt,x,y;
	n=read();
	q=read();
	tx=read();
	ty=read();
	if(tx>ty)swap(tx,ty);
	for(int i=1;i<=n;i++)
	{
		qz[i]=read();
	} 
	build(1,n,1);
	for(int i=1;i<=q;i++)
	{
		opt=read();
		x=read();
		y=read();
		if(opt==2)
		{
			struct jz sth=query(x,y,1);
			printf("%.9lf\n",max(max(sth.a[3][1],sth.a[3][2]),sth.a[3][3]));
		}
		else
		{
			change(x,1,y);
		}
	}
	return 0;
}