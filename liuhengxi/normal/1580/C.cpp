#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,B=255;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,b,x[N],y[N],bl[N],ans[N],last[N];
struct dif
{
	int a[N];
	void modify(int l,int r,int x){a[l]+=x;a[r]-=x;}
	void finish(){F(i,0,m-1)a[i+1]+=a[i];}
	int &operator[](int x){return a[x];}
}e;
struct block
{
	int a[N],c[N];
	void modify(int l,int r,int x)
	{
		F(i,bl[l],bl[r])c[i]+=x;
		F(i,bl[l]*b,l)a[i]-=x;
		F(i,bl[r]*b,r)a[i]+=x;
	}
	int query(int p){return a[p]+c[bl[p]];}
}d[B];
struct oper
{
	int p,k,t;
	bool operator<(oper b)const{return k!=b.k?k<b.k:t<b.t;}
}p[N];
int main()
{
	read(n);read(m);while(b*b<n)++b;b>>=1;
	F(i,0,max(n,m)+1)bl[i]=i/b;
	F(i,0,n)read(x[i]),read(y[i]),last[i]=-1;
	F(i,0,m)
	{
		int tmp=0,k;
		read(p[i].p);p[i].p=3-2*p[i].p;
		read(p[i].k);--p[i].k;p[i].t=i;
		k=p[i].k;
		if((tmp=x[k]+y[k])<b)
		{
			int j=((~last[k]?last[k]:i)+x[k])%tmp;
			last[k]=~last[k]?-1:i;
			if(j+y[k]>tmp)
			{
				d[tmp].modify(j,tmp,p[i].p);
				d[tmp].modify(0,j+y[k]-tmp,p[i].p);
			}
			else d[tmp].modify(j,j+y[k],p[i].p);
		}
		F(j,1,b)ans[i]+=d[j].query(i%j);
	}
	sort(p,p+m);
	for(int i=0,l=0,r=0;i<n;++i,l=r)
	{
		int last=-1;
		while(r<m&&p[r].k==i)++r;
		if(x[i]+y[i]<b)continue;
		F(j,l,r)
		{
			if(~last)
			{
				last+=x[i];
				if(last<p[j].t)
				{
					int tmp=x[i]+y[i];
					for(int k=last;k<p[j].t;k+=tmp)
					{
						int kk=min(k+y[i],p[j].t);
						e.modify(k,kk,1);
					}
				}
				last=-1;
			}
			else last=p[j].t;
		}
		if(~last)
		{
			last+=x[i];
			if(last<m)
			{
				int tmp=x[i]+y[i];
				for(int k=last;k<m;k+=tmp)
				{
					int kk=min(k+y[i],m);
					e.modify(k,kk,1);
				}
			}
		}
	}
	e.finish();
	F(i,0,m)ans[i]+=e[i];
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}