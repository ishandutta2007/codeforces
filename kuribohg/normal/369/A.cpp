#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,d,lazy,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d);
		if(d==1)
		{
			if(m) m--;
			else ans++;
		}
		else if(d==2) lazy++;
		if(lazy>=k+m) ans+=lazy-k-m,k=m=0,lazy=0;
	}
	printf("%d\n",ans);
	return 0;
}