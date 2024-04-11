#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e3+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int tt,n,m;
char s[N][N];
int main()
{
	read(tt);
	while(tt--)
	{
		int ans=1,all=1;
		read(n);read(m);
		F(i,0,n)scanf("%s",s[i]);
		F(i,0,n)F(j,0,m)if(s[i][j]=='#')ans=(ans<<1)%MOD;else all=0;
		ans-=all;
		printf("%d\n",ans);
	}
	return 0;
}