#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,t[MAXN],tot;
int fac[MAXN];
char a[MAXN];
char b[MAXN];
void work(int n,int w)
{
	int nn=n;
	for(int i=2;i*i<=nn;i++)
		if(n%i==0)
		{
			t[i]+=w,n/=i;
			while(n%i==0) t[i]+=w,n/=i;
		}
	if(n>1) t[n]+=w;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<10;i++) fac[i]=fac[i-1]*i;
	scanf("%d%s",&n,a);
	for(int i=0;i<n;i++) work(fac[a[i]-'0'],1);
	while(t[7]!=0) work(fac[7],-1),b[tot++]='7';
	while(t[5]!=0) work(fac[5],-1),b[tot++]='5';
	while(t[3]!=0) work(fac[3],-1),b[tot++]='3';
	while(t[2]!=0) work(fac[2],-1),b[tot++]='2';
	puts(b);
	return 0;
}