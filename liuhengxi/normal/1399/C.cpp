#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=500;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,w[N],t[2*N];
bool v[2*N][N];
int main()
{
	read(T);
	while(T--)
	{
		int ans=0;
		read(n);
		F(i,0,n)read(w[i]),--w[i];
		F(i,0,2*n)t[i]=0;
		F(i,0,2*n)F(j,0,n)v[i][j]=false;
		F(i,0,n)F(j,0,i)
		{
			int s=w[i]+w[j];
			if(v[s][i]||v[s][j])continue;
			++t[s];
			if(t[s]>ans)ans=t[s];
			v[s][i]=v[s][j]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}