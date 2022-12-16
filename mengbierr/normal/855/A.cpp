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
string s[105];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		bool ac=0;
		for(int j=1;j<i;j++)
		{
			if(s[i]==s[j])
			{
				ac=1;
				printf("YES\n");
				break;
			}
		}
		if(!ac)
		{
			printf("NO\n");
		}
	}
}