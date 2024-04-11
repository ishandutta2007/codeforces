#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[222222],b[222222];
int ord[222222],alen,blen,x,l,r;
bool check(int x)
{
	int p=0;
	for (int i=0;i<alen;i++)
	{
		if (ord[i]<=x) continue;
		if (a[i]==b[p]) p++;
		if (p==blen) return 1;
	}
	return 0;
}
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	alen=strlen(a);
	blen=strlen(b);
	for (int i=1;i<=alen;i++)
	{
		scanf("%d",&x);
		ord[x-1]=i;
	}
	l=0;r=alen;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}