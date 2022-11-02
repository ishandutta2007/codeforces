#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'|ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
const int maxn=1e6+5;
int tot,n,k,ed[30],st[30];
char s[maxn];
bool flag;
int main()
{
	n=read(),k=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		int ch=s[i]-'A';
		if (!st[ch]) st[ch]=i;
		ed[ch]=i;
	}
	for (int i=1;i<=n;i++)
	{
		int ch=s[i]-'A';
		if(st[ch]==i)
		tot++;
		if(tot>k)
		{flag=1;break;}
		if(ed[ch]==i) 
		tot--;
	}
	if (flag) printf("YES"); 
	else printf("NO"); 
}
/*
 
*/