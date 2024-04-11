#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("-1"),0
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
int n,a[N],t1[N],t2[N],cnt,sta[N],top,sta2[N],top2,tar;
int main()
{
	read(n);
	F(i,0,n)read(a[i]),t1[i]=t2[i]=-1;
	for(int i=n-1;~i;--i)
	{
		if(a[i]==1)
		{
			t1[i]=cnt++;
			sta[top++]=i;
			++tar;
		}
		if(a[i]==2)
		{
			if(top)
			{
				t1[i]=t1[sta[--top]];
				sta2[top2++]=i;
			}
			else fail;
			++tar;
		}
		if(a[i]==3)
		{
			if(top&&!top2)sta2[top2++]=sta[--top];
			if(top2)
			{
				t2[sta2[--top2]]=cnt;
				t1[i]=cnt++;
				sta2[top2++]=i;
			}
			else fail;
			tar+=2;
		}
	}
	printf("%d\n",tar);
	F(i,0,n)
	{
		if(~t1[i])printf("%d %d\n",n-t1[i],i+1);
		if(~t2[i])printf("%d %d\n",n-t2[i],i+1);
	}
	return 0;
}