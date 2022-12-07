#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[30],g,c,ans[100010],tot,sum;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
	for(int i=0;i<n;i++) g=gcd(g,a[i]);
	for(int i=0;i<n;i++) a[i]/=g;
	for(int i=0;i<n;i++) if(a[i]&1) c++;
	if(!(g&1))
	{
		printf("%d\n",g);
		for(int i=0;i<n;i++)
			while(a[i]--) ans[++tot]=i;
		for(int i=1;i<=tot;i++) ans[tot+tot+1-i]=ans[i];
		for(int i=1;i<=g/2;i++)
			for(int j=1;j<=tot+tot;j++)
				printf("%c",(char)(ans[j]+'a'));
	}
	else if(c>=2)
	{
		for(int i=0;i<n;i++) a[i]*=g;
		puts("0");
		for(int i=0;i<n;i++)
			while(a[i]--) printf("%c",(char)(i+'a'));
	}
	else
	{
		printf("%d\n",g);
		int len=sum/g;
		for(int i=0;i<n;i++)
		{
			if(a[i]&1) ans[(sum/g+1)>>1]=i,a[i]--;
			while(a[i]) a[i]-=2,ans[++tot]=i,ans[len--]=i;
		}
		for(int i=1;i<=g;i++)
			for(int j=1;j<=sum/g;j++)
				printf("%c",(char)(ans[j]+'a'));
	}
	return 0;
}