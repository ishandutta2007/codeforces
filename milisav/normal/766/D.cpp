#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
struct disj
{
	int op;
	int p;
	int h;
};
struct word
{
	char s[25];
	int a,b,c,d;
	int ind;
};
using namespace std;
disj a[200000];
int n,m,q;
int d,e,f,g;
word b[200000];
bool operator <(word x,word y)
{
	return x.a<y.a || (x.a==y.a && x.b<y.b) || (x.a==y.a && x.b==y.b && x.c<y.c) || (x.a==y.a && x.b==y.b && x.c==y.c && x.d<y.d);
}
char s1[25];
int o;
/*int par(int z)
{
	if(z==-1) return -1;
	int z1=z,z2;
	while(a[z1].p!=z1) z1=a[z1].p;
	while(a[z].p!=z1)
	{
		z2=z;
		z=a[z].p;
		a[z2].p=z1;
	}
	return z1;
}*/
int par(int z)
{
	if(z==-1) return z;
	if(a[z].p==z) return z;
	a[z].p=par(a[z].p);
	return a[z].p;
}
word c;
int unite(int x,int y)
{
    if(x==-1) return y;
    if(y==-1) return x;
	int z;
	x=par(x);
	y=par(y);
	if(a[x].h>=a[y].h)
	{
		if(a[x].h==a[y].h) a[x].h++;
		a[y].p=x;
		return x;
	}
	else
	{
		a[x].p=y;
		return y;
	}
}
int binary()
{
	int l=0;
	int r=n-1;
	int mid=(l+r)/2;
	while(l<=r)
	{
		if(c<b[mid]) r=mid-1;
		else
		{
			if(b[mid]<c) l=mid+1;
			else return mid;
		}
		mid=(l+r)/2;
	}
	while(mid<n && b[mid]<c) mid++;
	while(mid>0 && c<b[mid]) mid--;
	return mid;
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	int l=0;
	int t;
	char d='a'-1;
	for(int i=0;i<n;i++)
	{
		scanf("%s",b[i].s);
		t=strlen(b[i].s);
		for(int j=t;j<20;j++) b[i].s[j]=d;
		l=0;
		for(int j=0;j<20;j++)
		{
			l=l*27+b[i].s[j]-d;
			if(j==4)
			{
				b[i].a=l;
				l=0;
			}
			if(j==9)
			{
				b[i].b=l;
				l=0;
			}
			if(j==14)
			{
				b[i].c=l;
				l=0;
			}
			if(j==19)
			{
				b[i].d=l;
				l=0;
			}
		}
		b[i].ind=i;
		a[i].p=i;
		a[i].op=-1;
		a[i].h=1;
	}
	sort(b,b+n);
	int x;
	int y;
	int xp, yp;
	int z,w;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&o);
		scanf("%s",c.s);
		t=strlen(c.s);
		for(int j=t;j<20;j++) c.s[j]=d;
		l=0;
		for(int j=0;j<20;j++)
		{
			l=l*27+c.s[j]-d;
			if(j==4)
			{
				c.a=l;
				l=0;
			}
			if(j==9)
			{
				c.b=l;
				l=0;
			}
			if(j==14)
			{
				c.c=l;
				l=0;
			}
			if(j==19)
			{
				c.d=l;
				l=0;
			}
		}
		x=binary();
		if(b[x]<c || c<b[x]) return 0;
		scanf("%s",c.s);
		t=strlen(c.s);
		for(int j=t;j<20;j++) c.s[j]=d;
		l=0;
		for(int j=0;j<20;j++)
		{
			l=l*27+c.s[j]-d;
			if(j==4)
			{
				c.a=l;
				l=0;
			}
			if(j==9)
			{
				c.b=l;
				l=0;
			}
			if(j==14)
			{
				c.c=l;
				l=0;
			}
			if(j==19)
			{
				c.d=l;
				l=0;
			}
		}
		y=binary();
		if(b[y]<c || c<b[y]) return 0;
		xp=par(x);
		yp=par(y);
		if(o==1) 
		{
			if(a[yp].op!=xp)
			{
				printf("YES");
				if(xp!=yp)
				{
				    x=a[xp].op; //antonim
				    y=a[yp].op; //antonim
				    x=par(x); //roditelj antonima
				   	y=par(y); //roditelj antonima
				    z=unite(xp,yp); //z su ujedinjeni sinonimi
				    w=unite(x,y); //w su ujedinjeni antonimi
				    if(z!=-1) a[z].op=w;
				    if(w!=-1) a[w].op=z;
				}
			}
			else printf("NO");
			
		}
		else
		{
			if(xp!=yp) 
			{
				printf("YES");
				x=a[xp].op; //antonim
				y=a[yp].op; //antonim
				z=unite(yp,x); //sinonimi se ujedinjuju
				w=unite(xp,y); //sinonimi se ujedinjuju
				a[z].op=w;
				a[w].op=z;
			}
			else printf("NO");
		}
		printf("\n");
	}
	for(int i=0;i<q;i++)
	{
		scanf("%s",c.s);
		t=strlen(c.s);
		for(int j=t;j<20;j++) c.s[j]=d;
		l=0;
		for(int j=0;j<20;j++)
		{
			l=l*27+c.s[j]-d;
			if(j==4)
			{
				c.a=l;
				l=0;
			}
			if(j==9)
			{
				c.b=l;
				l=0;
			}
			if(j==14)
			{
				c.c=l;
				l=0;
			}
			if(j==19)
			{
				c.d=l;
				l=0;
			}
		}
		x=binary();
		scanf("%s",c.s);
		t=strlen(c.s);
		for(int j=t;j<20;j++) c.s[j]=d;
		l=0;
		for(int j=0;j<20;j++)
		{
			l=l*27+c.s[j]-d;
			if(j==4)
			{
				c.a=l;
				l=0;
			}
			if(j==9)
			{
				c.b=l;
				l=0;
			}
			if(j==14)
			{
				c.c=l;
				l=0;
			}
			if(j==19)
			{
				c.d=l;
				l=0;
			}
		}
		y=binary();
		xp=par(x);
		yp=par(y);
		if(xp==yp) printf("1\n");
		else
		{
		    x=a[xp].op;
		    y=a[yp].op;
		    if(x!=-1) x=par(x);
		    if(y!=-1) y=par(y);
			if(x==yp || y==xp) printf("2\n");
			else printf("3\n");
		}
	}
	return 0;
}