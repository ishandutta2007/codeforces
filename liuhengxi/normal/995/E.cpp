#include<cstdio>
#include<cstdlib>
#include<map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105,M=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int u,v,p,a[M][N],b[N];
map<int,int> s;
int inv(int aa)
{
	long long a=aa,c=1;
	int b=p-2;
	while(b)
	{
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return (int)c;
}
int main()
{
	read(u);read(v);read(p);
	srand((u^v)+(v^p));
	for(int k=0;true;++k)
	{
		int uu=u,vv=v;
		F(i,0,100)
		{
			a[k][i]=rand()%3+1;
			if(a[k][i]==1)uu=(uu+1)%p;
			if(a[k][i]==2)uu=(uu+p-1)%p;
			if(a[k][i]==3)uu=inv(uu);
		}
		if(k%100==0)srand(rand()^uu);
		if(k%200000==0)s.clear(),k=0;
		s[uu]=k+1;
		F(i,0,100)
		{
			b[i]=rand()%3+1;
			if(b[i]==1)vv=(vv+p-1)%p;
			if(b[i]==2)vv=(vv+1)%p;
			if(b[i]==3)vv=inv(vv);
		}
		if(s[vv])
		{
			int kk=s[vv]-1;
			puts("200");
			F(i,0,100)printf("%d ",a[kk][i]);
			for(int i=99;~i;--i)printf("%d ",b[i]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}