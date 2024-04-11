#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p[N];bool sb,fsb[N],kill[N];
int main()
{
	read(n);
	F(i,0,n)read(p[i]),--p[i];
	F(i,0,n)if(p[i]==i)
	{
		puts("YES");
		F(j,0,n)if(j!=i)printf("%d %d\n",j+1,i+1);
		return 0;
	}
	F(i,0,n)if(p[p[i]]==i)
	{
		fsb[i]=fsb[p[i]]=true;
		F(j,0,n)if(!fsb[j])
		{
			int cnt=0;
			fsb[j]=true;
			for(int k=p[j];k!=j;k=p[k])fsb[k]=true,kill[k]=(++cnt)&1;
			if(!(cnt&1))sb=true;
		}
		if(sb)return puts("NO"),0;
		puts("YES");
		printf("%d %d\n",i+1,p[i]+1);
		F(j,0,n)if(j!=i&&j!=p[i])printf("%d %d\n",(kill[j]?i:p[i])+1,j+1);
		return 0;
	}
	puts("NO");
	return 0;
}