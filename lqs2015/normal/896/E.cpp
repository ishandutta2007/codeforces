#include<bits/stdc++.h>
using namespace std;
const int maxt=2e6;
const int magic=300,maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
int read()
{
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char())
    {
    	if (c=='-') f=1;
	}
    while(c>='0'&&c<='9')
           re=re*10+(c&15),c=Get_Char();
    if (f) return -re;
    return re;
}
int n,m,ans[555555],op[555555],l[555555],r[555555],x[555555],lp,rp,ll,rr,mx,cp;
int pa[magic+10],sz[magic+10],all,tag,lb[555555],rb[555555],a[555555],arr[magic+10],val[magic+10],fake[2222222],rt;
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void clear(int l,int r,int x)
{
	for (int i=1;i<=all;i++) 
	{
		if (val[i]) fake[val[i]]=0; 
		arr[i]=val[root(i)]-tag;
	}
	tag=0;
	for (int i=l;i<=r;i++)
	{
		if (arr[i]>x) arr[i]-=x;
	}
	for (int i=1;i<=all;i++)
	{
		sz[i]=1;
		if (fake[arr[i]])
		{
			pa[i]=fake[arr[i]];
			sz[fake[arr[i]]]++;
		}
		else
		{
			pa[i]=i;
			fake[arr[i]]=i;val[i]=arr[i];
		}
	}
}
void doit(int b)
{
	lp=b*magic+1;rp=min((b+1)*magic,n);all=rp-lp+1;
	for (int i=lp;i<=rp;i++) arr[i-lp+1]=a[i];
	tag=0;mx=0;
	for (int i=1;i<=all;i++) 
	{
		sz[i]=1;mx=max(mx,arr[i]);val[i]=0;
		if (fake[arr[i]]) 
		{
			pa[i]=fake[arr[i]];
			sz[fake[arr[i]]]++;
		}
		else
		{
			pa[i]=i;
			fake[arr[i]]=i;val[i]=arr[i];
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (lb[i]>b || rb[i]<b) continue;
		if (op[i]==1)
		{
			if (l[i]<=lp && r[i]>=rp)
			{
				if (mx-x[i]>x[i])
				{
					for (int j=tag+1;j<=tag+x[i];j++)
					{
						if (fake[j])
						{
							rt=fake[j];
							if (j+x[i]<=maxt && fake[j+x[i]])
							{
								fake[j]=0;val[rt]=0;
								sz[fake[j+x[i]]]+=sz[rt];
								pa[rt]=fake[j+x[i]];
							}
							else 
							{
								val[rt]+=x[i];
								fake[j]=0;
								fake[j+x[i]]=rt;
							}
						}
					}
					tag+=x[i];mx-=x[i];
				}
				else
				{
					for (int j=mx+tag;j>x[i]+tag;j--)
					{
						if (fake[j])
						{
							rt=fake[j];
							if (j-x[i]>=0 && fake[j-x[i]])
							{
								fake[j]=0;val[rt]=0;
								sz[fake[j-x[i]]]+=sz[rt];
								pa[rt]=fake[j-x[i]];
							}
							else 
							{
								val[rt]-=x[i];
								fake[j]=0;
								fake[j-x[i]]=rt;
							}
						}
					}
					mx=min(mx,x[i]);
				}
			}
			else
			{
				ll=max(1,l[i]-lp+1);rr=min(all,r[i]-lp+1);
				clear(ll,rr,x[i]);
			}
		}
		else
		{
			if (l[i]<=lp && r[i]>=rp)
			{
				int vl=x[i]+tag;
				if (vl>maxt || !fake[vl]) continue;
				ans[i]+=sz[root(fake[vl])];
			}
			else
			{
				ll=max(1,l[i]-lp+1);rr=min(all,r[i]-lp+1);
				clear(1,0,0);
				for (int j=ll;j<=rr;j++) 
				{
					if (arr[j]==x[i]) ans[i]++;
				}
			}
		}
	}
	for (int i=1;i<=all;i++)
	{
		fake[val[i]]=0;
	}
}
int main()
{
//	freopen("5.in","r",stdin);
//	freopen("5.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		op[i]=read();l[i]=read();r[i]=read();x[i]=read();
		lb[i]=(l[i]-1)/magic;rb[i]=(r[i]-1)/magic;
	}
	for (int i=0;i<=(n-1)/magic;i++)
	{
		doit(i);
	}
	for (int i=1;i<=m;i++) 
	{
		if (op[i]==2) printf("%d\n",ans[i]);
	}
	return 0;
}