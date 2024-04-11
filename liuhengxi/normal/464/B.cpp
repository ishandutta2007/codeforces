#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define FOR(k) for(i##k=0,id[k][0]=0,id[k][1]=1,id[k][2]=2\
;i##k<6;++i##k,next_permutation(a[k],a[k]+3))
#define x(i) a[i][id[i][0]]
#define y(i) a[i][id[i][1]]
#define z(i) a[i][id[i][2]]
#define fail {bad=true;break;}
using namespace std;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int a[8][3],id[8][3],i0,i1,i2,i3,i4,i5,i6,i7,i8,cnt,n[3];
long long len;
long long dist(int i,int j)
{
	long long xx=x(i)-x(j),yy=y(i)-y(j),zz=z(i)-z(j);
	return xx*xx+yy*yy+zz*zz;
}
int main()
{
	F(i,0,8)F(j,0,3)read(a[i][j]);
	FOR(0)FOR(1)FOR(2)FOR(3)FOR(4)FOR(5)FOR(6)FOR(7)
	{
		bool bad=false;
		len=LLINF;
		F(i,1,8)len=min(dist(0,i),len);
		F(i,0,8)
		{
			cnt=0;
			F(j,0,8)if(dist(i,j)==len)
			{
				if(cnt<3)n[cnt]=j;
				++cnt;
			}
			if(cnt!=3)fail;
			if(dist(n[0],n[1])!=len*2)fail;
			if(dist(n[0],n[2])!=len*2)fail;
			if(dist(n[1],n[2])!=len*2)fail;
		}
		if(!bad)
		{
			puts("YES");
			F(i,0,8)printf("%d %d %d\n",x(i),y(i),z(i));
			return 0;
		}
	}
	puts("NO");
	return 0;
}