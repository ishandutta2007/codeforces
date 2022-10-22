#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e4+5,MOD=723572389;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct modify
{
	int k,x;
	bool operator<(modify b)const{return k<b.k;}
}r[2*N];
int n,q,tot;
unsigned f[N];
bool p[N];
int main()
{
	read(n);read(q);
	f[0]=1;
	F(i,0,q)
	{
		read(r[i<<1].k);read(r[i<<1|1].k);--r[i<<1].k;
		read(r[i<<1].x);r[i<<1|1].x=-r[i<<1].x;
	}
	sort(r,r+(q<<=1));
	for(int i=0,j=0;i<n;++i)
	{
		while(j<q&&r[j].k==i)
		{
			if(r[j].x<0)F(i,-r[j].x,n+1)(f[i]+=MOD-f[i+r[j].x])%=MOD;
			else for(int i=n;i>=r[j].x;--i)(f[i]+=f[i-r[j].x])%=MOD;
			++j;
		}
		F(i,1,n+1)p[i]=p[i]||f[i];
	}
	F(i,1,n+1)tot+=p[i]?1:0;
	printf("%d\n",tot);
	F(i,1,n+1)if(p[i])printf("%d ",i);
	puts("");
	return 0;
}