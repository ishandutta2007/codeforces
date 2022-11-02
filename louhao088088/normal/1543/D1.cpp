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
int n,k,x,T;
signed main()
{
	
	T=read();
	while(T--)
	{
		n=read(),k=read();x=0;
		int t=1,y=1;printf("0\n",t);fflush(stdout);x=read();
		while(!x)
		{
			printf("%d\n",t);fflush(stdout);
			x=read();y++,t=(y-1)^y;	
		}
	}
}