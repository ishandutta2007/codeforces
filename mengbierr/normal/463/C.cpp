#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int x1,x2,y1,y2;
long long a[2005][2005],v[2005][2005],sx[5005],sy[5005],max1=-1,max2=-1;
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			sx[i+j]+=a[i][j];
			sy[i-j+2000]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(max1<sx[i+j]+sy[i-j+2000]-a[i][j])
			{
				max1=sx[i+j]+sy[i-j+2000]-a[i][j];
				x1=i,y1=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2!=(x1+y1)%2)
			{
				if(max2<sx[i+j]+sy[i-j+2000]-a[i][j])
				{
					max2=sx[i+j]+sy[i-j+2000]-a[i][j];
					x2=i,y2=j;
				}
			}
		}
	}
	cout<<max1+max2<<endl;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
}