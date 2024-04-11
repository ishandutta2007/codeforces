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
char s[1000005];int n,k,first[28],last[28];
int main()
{
	n=read(),k=read();int now=0;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(!first[s[i]-'A'])
		first[s[i]-'A']=i;
	}
	for(int i=n;i;i--)
	{
		if(!last[s[i]-'A'])
		last[s[i]-'A']=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(first[s[i]-'A']==i)
		now++;
		if(now>k)
		{
			cout<<"YES";
			return 0;
		}
		if(last[s[i]-'A']==i)
		now--;
	}
	cout<<"NO";
}