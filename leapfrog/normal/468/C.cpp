//
//
#include<bits/stdc++.h>
using namespace std;
long long P,g,INF=1e18;
int main()
{
	scanf("%lld",&P),g=INF%P*3%P*3%P*3%P*3%P+1;
	return printf("%lld %lld\n",P-g+1,INF+P-g),0;
}