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
int temp,ans;
int main()
{
	int n=read();char ch;
	while(ch=getchar())
	{
		if((ch>='a'||ch<='z')&&(ch>='A'&&ch<='Z'))
		break;
		else if(ch=='\n')
		{
			ch=getchar();
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		if(ch>='A'&&ch<='Z')
		temp++;
		else if(ch==' ')
		{
			ans=max(ans,temp);
			temp=0;
		}ch=getchar();
	}
	
	ans=max(ans,temp);
	cout<<ans;
}