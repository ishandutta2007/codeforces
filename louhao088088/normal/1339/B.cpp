#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[100005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
    	m=read();for(int j=1;j<=m;j++)a[j]=read();
    	sort(a+1,a+m+1);
    	if(m%2==1)
    	{
    		printf("%d ",a[m/2+1]);
    		for(int j=1;j<=m/2;j++)printf("%d %d ",a[m/2+1+j],a[m/2-j+1]);
		}
    	else 
    	{
    		printf("%d ",a[m/2]);
    		for(int j=1;j<m/2;j++)printf("%d %d ",a[m/2+j],a[m/2-j]);
    		printf("%d ",a[m]);
		}
    	puts("");
	}
    return 0;
}