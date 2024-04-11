#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int tt,n;
bool is[N];
int main()
{
	read(tt);
	while(tt--)
	{
		int sec=0,res=0,l=0,r=0;
		read(n);
		while(res==0)
		{
			++sec;
			printf("? %d 1\n",sec);
			F(i,0,sec)printf("%d ",i+1);
			printf("\n%d\n",sec+1);
			fflush(stdout);
			read(res);
		}
		l=0;r=sec;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			printf("? %d 1\n",mid);
			F(i,0,mid)printf("%d ",i+1);
			printf("\n%d\n",sec+1);
			fflush(stdout);
			read(res);
			if(res==0)l=mid;
			else r=mid;
		}
		int &fir=l;
		F(i,0,n)is[i]=false;
		F(i,0,fir)is[i]=true;
		F(i,fir+1,sec)is[i]=true;
		F(i,sec+1,n)
		{
			printf("? 1 1\n%d\n%d\n",sec+1,i+1);
			fflush(stdout);
			read(res);
			is[i]=res==0;
		}
		int ans=0;
		F(i,0,n)ans+=is[i]?1:0;
		printf("! %d ",ans);
		F(i,0,n)if(is[i])printf("%d ",i+1);
		puts("");
		fflush(stdout);
	}
	return 0;
}