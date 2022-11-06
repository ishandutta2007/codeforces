#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
int Abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int a[1010000],b[1001][1001];
char s[1001000];
long long k[10010000];
int main()
{int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);int len=strlen(s);
		int s0=0,s1=0;bool ok1=0,ok2=0;
		for(int j=0;j<len;j++)
		{
			if(s[j]=='(')s0++;
			if(s[j]==')')s1++;
			if(s1>s0)ok1=1;
		}
		s0=0;s1=0;
		for(int j=len-1;j>=0;j--)
		{
			if(s[j]=='(')s0++;
			if(s[j]==')')s1++;
			if(s0>s1)ok2=1;
		}
		if(ok1&&ok2)continue;
		k[s0-s1+1000000]++;
	}
	long long ans=0;
	ans+=k[1000000]*k[1000000];
	for(int i=-1000000;i<0;i++)
	{
		ans+=k[i+1000000]*k[-i+1000000];
	}
	printf("%lld",ans);return 0;
}