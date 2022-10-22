#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,M=1e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],q;
bool e[M];
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]),e[a[i]]=true;
	sort(a,a+n,greater<int>());
	read(q);
	while(q--)
	{
		int x,ans=k+1;read(x);
		F(i,0,n)
		{
			int y=x;
			F(j,1,k+1)
			{
				y-=a[i];
				if(y==0)ans=min(ans,j);
				if(y<0)break;
				F(p,1,ans-j)if(y%p==0&&y/p<M&&e[y/p]){ans=p+j;break;}
			}
		}
		printf("%d\n",ans==k+1?-1:ans);
	}
	return 0;
}