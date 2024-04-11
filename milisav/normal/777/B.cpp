#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int s[15];
int m[15];
char d[2000];
int r=0;
int minimum(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",d);
	for(int i=0;i<n;i++) s[d[i]-'0']++;
	scanf("%s",d);
	for(int i=0;i<n;i++) m[d[i]-'0']++;
	m[10]=0;
	r=0;
	int a=0,b=0;
	for(int i=9;i>=0;i--)
	{
		a+=m[i];
		b=s[i];
		if(a>b) a=a-b;
		else 
		{
			r+=(b-a);
			a=0;
		}
		b=0;
	}
	printf("%d\n",r);
	a=0;
	b=0;
	r=0;
	for(int i=8;i>=0;i--)
	{
		a+=m[i+1];
		b=s[i];
		if(a>b)
		{
			r+=b;
			a=a-b;
		}
		else 
		{
			r+=a;
			a=0;
		}
		b=0;
	}
	printf("%d",r);
	return 0;
}