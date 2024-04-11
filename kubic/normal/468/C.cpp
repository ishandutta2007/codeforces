#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,up=1e18,t=1e18;
int main()
{
	scanf("%lld",&a);t=up%a*9%a*9%a;
	printf("%lld %lld\n",a-t,up+a-t-1);return 0;
}