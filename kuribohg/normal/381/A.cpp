#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,l,r,a[1010],ans[2],who;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=1,r=n;
	while(l<=r)
	{
		who^=1;
		if(a[l]>a[r]) ans[who]+=a[l++];
		else ans[who]+=a[r--];
	}
	printf("%d %d\n",ans[1],ans[0]);
	return 0;
}