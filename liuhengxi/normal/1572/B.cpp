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
int t,n,a[N],m,op[N];
void operate(int x){a[x+2]=a[x+1]=(a[op[m++]=x]^=a[x+1]^a[x+2]);}
void fsb(int l,int r)
{
	for(int i=r-3;i>=l;i-=2)operate(i);
	for(int i=l;i<r-2;i+=2)operate(i);
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);m=0;
		F(i,0,n)read(a[i]),m^=a[i];
		if(m)puts("NO");
		else
		{
			bool done=false;
			if(n&1)fsb(0,n),done=true;
			else
			{
				int t=a[0];
				for(int i=1;i<n;t^=a[i]^a[i+1],i+=2)
				{
					if(!t)
					{
						fsb(0,i);fsb(i,n);
						done=true;break;
					}
				}
			}
			if(done)
			{
				puts("YES");
				printf("%d\n",m);
				F(i,0,m)printf("%d ",op[i]+1);
				puts("");
			}
			else puts("NO");
		}
	}
	return 0;
}