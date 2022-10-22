#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long int k,x;
	scanf("%d",&n);
	while(n--) {
		scanf("%lld %lld",&k,&x);
		printf("%lld\n",x+(k-1)*9);
	}
	return 0;
}