#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
string s,t[1005];
int main()
{
	t[1]="Danil";t[2]="Olya";t[3]="Slava";t[4]="Ann";t[5]="Nikita";
	cin>>s;
	int n=s.length(),sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			bool ac=1;
			if(s.length()-i+1<t[j].length())
			{
				ac=0;
			}
			else
			{
				for(int k=0;k<t[j].length();k++)
				{
					if(t[j][k]!=s[i+k])
					{
						ac=0;
						break;
					}
				}
			} 
			if(ac) sum++;
		}
	}
	if(sum==1)
	puts("YES");
	else puts("NO");
}