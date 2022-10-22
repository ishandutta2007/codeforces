#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=100,M=70;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int a[N];
char ans[N][M+5];
int main()
{
	int T;read(T);
	while(T--)
	{
		int n;read(n);
		F(i,0,n)read(a[i]);
		F(j,0,M)ans[0][j]='b';
		F(i,0,n)
		{
			F(j,0,M)ans[i+1][j]=ans[i][j];
			ans[i+1][a[i]]^=1;
		}
		F(i,0,n+1)puts(ans[i]);
	}
	return 0;
}