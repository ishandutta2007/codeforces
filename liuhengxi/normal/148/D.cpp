#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
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
int w,b;
double f[N][N][3];
int main()
{
	read(w);read(b);
	F(i,0,w+1)F(j,0,b+1)
	{
		double prob=i/double(i+j);
		if(i+j>0)
		{
			if(j)f[i][j][0]=f[i][j-1][1]*(1-prob)+prob;
			else f[i][j][0]=1.0;
		}
		if(j>0)
		{
			f[i][j][1]=f[i][j-1][2]*(1-prob);
		}
		if(i>0)f[i][j][2]+=prob*f[i-1][j][0];
		if(j>0)f[i][j][2]+=(1-prob)*f[i][j-1][0];
	}
	printf("%.12lf\n",f[w][b][0]);
	return 0;
}