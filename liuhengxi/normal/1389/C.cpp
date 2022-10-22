#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N],ans;
char str[N+1];
int main()
{
	read(t);
	while(t--)
	{
		n=0;
		scanf("%s",str);
		while(str[n])++n;
		F(i,0,n)a[i]=str[i]-'0';
		ans=0;
		F(i,0,10)F(j,0,10)
		{
			int tmp=0;
			F(k,0,n)
			{
				if(tmp&1)
				{
					if(a[k]==j)++tmp;
				}
				else
				{
					if(a[k]==i)++tmp;
				}
			}
			if(tmp>ans)ans=tmp;
		}
		if(ans&1)ans^=1;
		F(i,0,10)
		{
			int tmp=0;
			F(k,0,n)if(a[k]==i)++tmp;
			if(tmp>ans)ans=tmp;
		}
		ans=n-ans;
		printf("%d\n",ans);
	}
	return 0;
}