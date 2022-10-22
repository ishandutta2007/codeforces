#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=110;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m;
char a[N][N+1];
int main()
{
	read(t);
	while(t--)
	{
		int ans=0;
		read(n);read(m);
		F(i,0,n)scanf("%s",a[i]);
		F(i,0,n-1)if(a[i][m-1]=='R')++ans;
		F(i,0,m-1)if(a[n-1][i]=='D')++ans;
		printf("%d\n",ans);
	}
	return 0;
}