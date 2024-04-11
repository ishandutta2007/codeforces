#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,d=1,s,c,a[N+1];
void add(int x,int y)
{
	for(++x;x<=n;x+=x&-x)a[x]+=y;
}
int sum(int x)
{
	int ans=0;
	for(;x;x-=x&-x)ans+=a[x];
	return ans;
}
int main()
{
	read(n);read(q);
	c=n;
	F(i,0,n)add(i,1);
	while(q--)
	{
		int op;read(op);
		if(op==1)
		{
			int p;read(p);
			if(p>c/2)
			{
				p=c-p;
				F(i,0,p)
				{
					int j=s+d*(c-1-i),k=s+d*(c-2*p+i);
					int a=sum(j+1)-sum(j);
					add(j,-a);add(k,a);
				}
				c-=p;
				s+=(c-1)*d;
				d*=-1;
			}
			else
			{
				F(i,0,p)
				{
					int j=s+d*i,k=s+d*(2*p-1-i);
					int a=sum(j+1)-sum(j);
					add(j,-a);add(k,a);
				}
				c-=p;
				s+=p*d;
			}
		}
		else
		{
			int l,r;read(l);read(r);--r;
			int x=s+l*d,y=s+r*d;
			if(x>y)x^=y^=x^=y;
			++y;
			printf("%d\n",sum(y)-sum(x));
		}
	}
	return 0;
}