#include<iostream>
#include<cstdio>
using namespace std;
int cos[111111],n,t[111111],a,b;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	for (int i=1;i<=n;i++)
	{
		cos[i]=cos[i-1]+20;
		a=lower_bound(t+1,t+n+1,t[i]-89)-t-1;
		if (cos[a]+50<cos[i]) cos[i]=cos[a]+50;
		b=lower_bound(t+1,t+n+1,t[i]-1439)-t-1;
		if (cos[b]+120<cos[i]) cos[i]=cos[b]+120;
		printf("%d\n",cos[i]-cos[i-1]);
	}
	return 0;
}