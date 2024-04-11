#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
double f[N/*I*/][N/*I kill*/][N/*kill me*/];
int a,b,c,n;
int main()
{
	read(a);read(b);read(c);
	n=a>b?a:b;n=n>c?n:c;++n;
	F(i,0,n)F(j,0,n)F(k,0,n)
	{
		int tot=((i+j+k)*(i+j+k)-i*i-j*j-k*k)>>1;
		if(!tot)f[i][j][k]=i==0?0.0:1.0;
		else
		{
			if(i)f[i][j][k]+=f[i-1][j][k]*i*k/tot;
			if(j)f[i][j][k]+=f[i][j-1][k]*i*j/tot;
			if(k)f[i][j][k]+=f[i][j][k-1]*j*k/tot;
		}
	}
	printf("%0.12lf %0.12lf %0.12lf \n",f[a][b][c],f[b][c][a],f[c][a][b]);
	return 0;
}