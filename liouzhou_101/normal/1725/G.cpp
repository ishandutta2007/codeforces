#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#include <set>
#define ll long long
using namespace std;
ll N;
ll lft, rgt;
ll ans;
int main(){
	scanf("%lld",&N);
	lft = N;
	rgt = 3*N;
	while(lft <= rgt){
		ll mid = (lft + rgt) >> 1;
		ll aug = mid - (mid / 2 + 1) / 2 - 1;
		if(mid / 2 >= 2) -- aug;
		if(aug >= N){
			ans = mid;
			rgt = mid-1;
		}else lft = mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}