#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;
ll N,M;
ll ans;
int main(){
	scanf("%lld%lld",&N,&M);
	ans = (M-1) * N;
	if(M == 1) ans += (N-1);
	printf("%lld\n", ans); 
	return 0;
}