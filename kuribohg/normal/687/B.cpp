#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=1000010;
int n,k,c[MAXN];
int M[MAXN];
bool p[MAXN];
int prime[MAXN],tot;
void fact(int n)
{
	int nn=n;
	for(int i=1;prime[i]*prime[i]<=nn;i++)
		if(n%prime[i]==0)
		{
			int c=1;
			n/=prime[i];
			while(n%prime[i]==0) c++,n/=prime[i];
			M[prime[i]]=max(M[prime[i]],c);
		}
	if(n>1) M[n]=max(M[n],1);
}
void test(int n)
{
	int nn=n;
	for(int i=2;i*i<=nn;i++)
		if(n%i==0)
		{
			int c=1;
			n/=i;
			while(n%i==0) c++,n/=i;
			if(c>M[i]) {puts("No");exit(0);}
		}
	if(n>1&&M[n]<1) {puts("No");exit(0);}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=2;i<=1000000;i++)
		for(int j=i+i;j<=1000000;j+=i)
			p[j]=true;
	for(int i=2;i<=1000000;i++) if(!p[i]) prime[++tot]=i;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) fact(c[i]);
	test(k);
	puts("Yes");
	return 0;
}