#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-10
#define md
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int p=1;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=i;j++)
		  p=p%n+1;
		printf("%d ",p);
	}
	return 0;
}