#include<bits/stdc++.h>
using namespace std;
#define double long double
const int maxn=4e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,k,x,T,a,b;
int get(int x,int y,int k)
{
	int num=1,res=0;
	while(x||y)
	{
		a=x%k;b=y%k;
		x=x/k;y=y/k;
		res=res+num*((b-a+k)%k);num=num*k;
	}
	return res;
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();x=0;
		int t=0,y=0;
		while(!x)
		{
			printf("%d\n",t);fflush(stdout);
			x=read();if(x)break;y++;if(y%2==0)t=get(y-1,y,k);
			else t=get(y,y-1,k);	
		}
	}
}