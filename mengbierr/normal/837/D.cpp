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
int N=5157;
int f[210][6005];
int n,k,num;long long x;
int main()
{
	n=read(),k=read();
	memset(f,-1,sizeof(f));
	int temp2,temp5;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		temp2=0,temp5=0;
		while(!(x%2)) temp5++,x>>=1;
		while(!(x%5)) temp2++,x/=1LL*5;
		for(int i=k;i>1;i--)
		{
			for(int j=temp2;j<=N;j++)
			{
				if(~f[i-1][j-temp2])
				{
					if(f[i-1][j-temp2]+temp5>f[i][j])
					f[i][j]=f[i-1][j-temp2]+temp5;
				}
			}
		}
		f[1][temp2]=max(f[1][temp2],temp5);
	}
	for(int i=1;i<=N;i++)
	{
		num=max(num,min(i,f[k][i]));
	}
	cout<<num;
}