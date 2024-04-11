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
int T,n,a[N],tot,zero,ans[N];
char s[N+1];
int main()
{
	read(T);
	while(T--)
	{
		int off=0;
		read(n);
		scanf("%s",s);
		F(i,0,n)a[i]=s[i]^48;
		tot=zero=0;
		F(i,0,n)
		{
			if(a[i])
			{
				if(zero)ans[i]=zero--;
				else ans[i]=++tot;
				if(zero>tot)tot=zero;
			}
			else
			{
				if(tot-zero)ans[i]=++zero;
				else ans[i]=1,++tot,++zero,++off;
			}
			ans[i]-=off;
		}
		off=1;
		F(i,0,n)if(ans[i]<off)off=ans[i];
		off=1-off;
		F(i,0,n)ans[i]+=off;
		printf("%d\n",tot);
		F(i,0,n)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}