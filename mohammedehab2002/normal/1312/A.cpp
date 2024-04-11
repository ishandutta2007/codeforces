#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		puts((n%m==0)? "YES":"NO");
	}
}