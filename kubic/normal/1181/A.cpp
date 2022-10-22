#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
ll x,y,z;
int main()
{
	scanf("%lld %lld %lld",&x,&y,&z);printf("%lld ",(x+y)/z);
	if(x%z+y%z<z) puts("0");else printf("%lld\n",z-max(x%z,y%z));
}