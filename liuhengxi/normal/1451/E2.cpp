#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<16)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],last[N];
void output()
{
	printf("! ");
	F(i,0,n)printf("%d ",a[i]);
	puts("");fflush(stdout);
}
void same(int u,int v)
{
	int dif,tmp;
	printf("AND %d %d\n",u+1,v+1);fflush(stdout);
	read(tmp);dif=a[u]^tmp;
	F(i,0,n)a[i]^=dif;
	output();
}
void dist()
{
	int tmp;
	printf("AND %d %d\n",1,last[1]+1);fflush(stdout);
	read(tmp);a[0]|=tmp;
	printf("AND %d %d\n",1,last[2]+1);fflush(stdout);
	read(tmp);a[0]|=tmp;
	F(i,1,n)a[i]^=a[0];
	output();
}
int main()
{
	read(n);
	F(i,1,n)
	{
		printf("XOR %d %d\n",1,i+1);fflush(stdout);
		read(a[i]);
	}
	F(i,0,n)last[i]=-1;
	F(i,0,n)
	{
		if(~last[a[i]])return same(last[a[i]],i),0;
		last[a[i]]=i;
	}
	dist();
	return 0;
}