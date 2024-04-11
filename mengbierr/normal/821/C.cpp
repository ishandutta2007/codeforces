#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> s;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int now=1,ans=0;
int main()
{
	int n=read();char ss[15];
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",ss);
		if(ss[0]=='a')
		{
			int x=read();
			s.push(x);
		}
		else
		{
			if(!s.empty())
			{
				if(s.top()==now)
				{
					s.pop();
				}
				else
				{
					ans++;
					while(!s.empty())
					s.pop();
				}
			}
			now++;
		}
	}
	cout<<ans;
	
}