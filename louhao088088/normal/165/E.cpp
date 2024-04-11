#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,x,a[1000005],f[(1<<22)+1];
int main()
{
	n=read();memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++)a[i]=read(),f[a[i]]=a[i];
	for(int i=0;i<=22;i++)
		for(int j=0;j<=(1<<22);j++)
			if(j&(1<<i)&&f[j^(1<<i)]!=-1)f[j]=f[j^(1<<i)];
	for(int i=1;i<=n;i++)
		x=a[i]^((1<<22)-1),printf("%d ",f[x]);
}