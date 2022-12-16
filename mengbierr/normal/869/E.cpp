#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct data
{
	int x[4];
	data(){}
	data(int q,int w,int e,int r)
	{
		x[0]=q;x[1]=w;x[2]=e;x[3]=r;
	}
	friend bool operator <(data x,data y)
	{
		for(int i=0;i<4;i++)
		{
			if(x.x[i]!=y.x[i])
			{
				return x.x[i]<y.x[i];
			}
		}
		return 0;
	}
};
ll RD()
{
	return (rand()<<15)|rand();
}
map<data,ll> h;
ll RAND()
{
	return (RD()<<31)+RD();
}
int n,m,q,tot;
int son[29000005][2],v[29000005];
int rt[10005];
void tochange(int &x,int y,int z,int l,int r,ll cv)
{
	if(!x) x=++tot;
	if(y==l&&z==r)
	{
		v[x]^=cv;
		return;
	}
	int mid=y+z>>1;
	if(r<=mid) tochange(son[x][0],y,mid,l,r,cv);
	else if(l>mid) tochange(son[x][1],mid+1,z,l,r,cv);
	else
	{
		tochange(son[x][0],y,mid,l,mid,cv);
		tochange(son[x][1],mid+1,z,mid+1,r,cv);
	}
}
void change(int x,int y,int z,int l,int r,int L,int R,ll cv)
{
	if(y==l&&z==r)
	{
		tochange(rt[x],1,m,L,R,cv);
		return;
	}
	int mid=y+z>>1;
	if(r<=mid) change(x<<1,y,mid,l,r,L,R,cv);
	else if(l>mid) change(x<<1|1,mid+1,z,l,r,L,R,cv);
	else
	{
		change(x<<1,y,mid,l,mid,L,R,cv);
		change(x<<1|1,mid+1,z,mid+1,r,L,R,cv);
	}
}
ll toask(int x,int y,int z,int p)
{
	ll re=v[x];
	if(!x||y==z) return re;
	int mid=y+z>>1;
	if(p<=mid) return re^toask(son[x][0],y,mid,p);
	else return re^toask(son[x][1],mid+1,z,p);
}
ll ask(int x,int y,int z,int p,int P)
{
	ll re=toask(rt[x],1,m,P);
	if(y==z) return re;
	int mid=y+z>>1;
	if(p<=mid) return re^ask(x<<1,y,mid,p,P);
	else
	{
		return re^ask(x<<1|1,mid+1,z,p,P);
	}
}
int main()
{
	n=read();m=read();q=read();
	while(q--)
	{
		int op=read(),x=read(),y=read(),xx=read(),yy=read();
		data t(x,y,xx,yy);
		if(op==1)
		{
			h[t]=(ll) RAND();
			change(1,1,n,x,xx,y,yy,h[t]);
		}
		else if(op==2)
		{
			change(1,1,n,x,xx,y,yy,h[t]);
		}
		else
		{
			printf(ask(1,1,n,x,y)==ask(1,1,n,xx,yy)?"Yes\n":"No\n");
		}
	}
	
}