#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,t,s,k,x,y;
bool flag[2005];
int main()
{
	t=read();
	while(t--)
	{
		memset(flag,true,sizeof flag);
		n=read(),s=read(),k=read();
		for(int i=1;i<=k;i++)
		{
			x=read();y=1000+x-s;
			if(y>0&&y<2000)flag[y]=false;
		}
		for(int i=0;i<=1001;i++)
			if((flag[1000-i]==1&&s-i>0)||(flag[i+1000]==1&&s+i<=n)){cout<<i<<endl;break;}
	}
	return 0;
}