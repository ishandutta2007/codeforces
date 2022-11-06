#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define re register
#define cmin(a,b) (a>(b)?a=(b):0)
#define cmax(a,b) (a<(b)?a=(b):0)
#define dmax(a,b) ((a)>(b)?(a):(b))
#define dmin(a,b) ((a)<(b)?(a):(b))
char ss[100100],s[100100];
int cc[100100];
int main()
{
	cc['a']=cc['e']=cc['i']=cc['o']=cc['u']=1;
	re int n,m;
	scanf("%s%s",s,ss);
	n=strlen(s);m=strlen(ss);
	if(n!=m)puts("No");
	else
	{
		for(re int i=0;i<n;i++)
		{
			if(cc[s[i]]!=cc[ss[i]])puts("No"),exit(0);
		}
	puts("Yes");}
}