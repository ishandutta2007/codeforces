#include <iostream>
#include <map>
using namespace std;
map<long long,int> m;
map<pair<int,int>,int> m2;
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	long long ans=0;
	while (n--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		long long tmp=y-1LL*x*a;
		ans+=m[tmp]-m2[{x,y}];
		m[tmp]++;
		m2[{x,y}]++;
	}
	printf("%I64d",2*ans);
}