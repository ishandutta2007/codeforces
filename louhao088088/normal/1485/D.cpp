#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=((x<<1)+(x<<3)+(ch^48));
	if(f==1)x=-x;return x;
}
int a[505][505],b[505][505],f[100],M=720720,n,m;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();if((i+j)%2==1)b[i][j]=M;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)%2==0)
			{
				for(int k=1;k<=31;k++)
				{
					int x=M-k*k*k*k;if(x>0&&x%a[i][j]==0)
					{
						b[i][j]=x;break;
					}
				}
			}
		cout<<b[i][j]<<" ";
		}cout<<endl;
	}
		
	
	
}