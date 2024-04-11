#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,a[N],c[N],m;
long long s[N];
inline long long sum(int l,int r){return r>l?s[r]-s[l]:s[n]-s[l]+s[r];}
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]);
	F(i,0,n)s[i+1]=s[i]+a[i];
	while(q--)
	{
		long long b;read(b);int ans,p=0;
		c[(m=1)-1]=0;
		F(i,0,n)if(sum(c[m-1],(i+1)%n)>b)c[m++]=i;
		ans=m;
		if(ans>1)
		{
			F(i,1,m-1)if(c[i+1]-c[i]<c[p+1]-c[p])p=i;
			F(i,c[p]+1,c[p+1]+1)
			{
				if(~p)
				{
					int cp=c[p];
					c[(m=1)-1]=cp;
					for(int i=0;m<ans;(++i)%=n)if(sum(c[m-1],(cp+i+1)%n)>b)c[m++]=(cp+i)%n;
					p=-1;
				}
				c[0]=i;
				F(j,1,m)
				{
					if(c[j]<c[j-1])c[j]=c[j-1];
					while(sum(c[j-1],c[j]+1)<=b)
					{
						(++c[j])%=n;
						if(c[j]==i)ans=ans<j?ans:j;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}