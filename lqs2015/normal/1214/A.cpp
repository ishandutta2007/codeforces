#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,d,e,x,mn;
int main()
{
	scanf("%d%d%d",&n,&d,&e);
	mn=n;
	for (int i=0;i*d<=n;i++)
	{
		x=n-i*d;
		mn=min(mn,x%(5*e));
	}
	printf("%d\n",mn);
	return Accepted;
}