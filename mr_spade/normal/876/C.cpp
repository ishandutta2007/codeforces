#include<cstdio>
#include<vector>
#define max(a,b) (a>b?a:b)
using std::vector;
int n;
vector<int>a;
inline int f(int x)
{
	int sum(0);
	while(x)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
signed main()
{
	scanf("%d",&n);
	for(register int i=max(n-81,0);i<=n;i++)
		if(i+f(i)==n)
			a.push_back(i);
	printf("%d\n",a.size());
	for(vector<int>::iterator k=a.begin();k!=a.end();k++)
		printf("%d ",*k);
	return putchar('\n'),0;
}