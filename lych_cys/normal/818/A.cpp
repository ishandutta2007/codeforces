#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	printf("%lld %lld %lld\n",n/2/(k+1),n/2/(k+1)*k,n-n/2/(k+1)-n/2/(k+1)*k);
	return 0;
}