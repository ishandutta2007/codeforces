#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,LogN=21;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int m,n,q,lg[N],logn,a[N],s[N][LogN];
int query(int l,int r)
{
	int k=lg[r-l];
	return max(s[l][k],s[r-(1<<k)][k]);
}
int main()
{
	F(i,1,N)lg[i]=lg[i-1]+((2<<lg[i-1])<=i);
	read(m,n);
	logn=lg[n];
	F(i,0,n)s[i][0]=read(a[i]);
	read(q);
	F(i,0,logn)F(j,0,n+1-(2<<i))s[j][i+1]=max(s[j][i],s[j+(1<<i)][i]);
	while(q--)
	{
		int vs,is,vt,it,k;
		read(vs,is,vt,it,k);--is,--it;
		if((vs-vt)%k||(is-it)%k)puts("NO");
		else if(is==it)puts("YES");
		else
		{
			if(is>it)swap(is,it),swap(vs,vt);
			int up=(m-vs)/k*k+vs;
			if(query(is,it)<up)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}