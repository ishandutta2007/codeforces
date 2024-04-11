#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n&1) puts("0");
	else printf("%lld\n",1ll<<(n>>1));
}