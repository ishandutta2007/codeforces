#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

ll x[4];

void solve(int tc){
	rep(i, 4)scanf("%lld", x+i);
	if(x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 0){
		puts("0");
		return;
	}
	if(x[0] == 1 && x[1] == 0 && x[2] == 0 && x[3] == 0){
		puts("00");
		return;
	}
	if(x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 1){
		puts("11");
		return;
	}
	if(x[0] == 0 && x[1] == 1 && x[2] == 0 && x[3] == 0){
		puts("01");
		return;
	}
	if(x[0] == 0 && x[1] == 0 && x[2] == 1 && x[3] == 0){
		puts("10");
		return;
	}
	if(x[0] == 0 && x[1] == 0 && x[2] == 0){
		ll m = sqrt(x[3] + x[3]) + 1;
		if(m * (m-1) != x[3] + x[3]){
			puts("Impossible");
			return;
		}
		else{
			rep(i, m)printf("1");
		}
		return;
	}
	
	if(x[3] == 0 && x[1] == 0 && x[2] == 0){
		ll m = sqrt(x[0] + x[0]) + 1;
		if(m * (m-1) != x[0] + x[0]){
			puts("Impossible");
			return;
		}
		else{
			rep(i, m)printf("0");
		}
		return;
	}
	ll n;
	n = sqrt(x[0] + x[0]) + 1;
	int ok = 1;
	if(n * (n-1) != x[0] + x[0])ok = 0;
	ll m = sqrt(x[3] + x[3]) + 1;
	if(m * (m-1) != x[3] + x[3])ok = 0;
	if(ok == 0){
		puts("Impossible");
		return;
	}
	if(x[0] + x[1] + x[2] + x[3] != (n+m) * (n+m-1) / 2){
		puts("Impossible");
		return;
	}
	rep(i, x[2] / n)printf("1");
	ll u = x[2] - n * (x[2] / n);
	if(u != 0){
		rep(i, n-u)printf("0");
		printf("1");
		rep(i, u)printf("0");
		rep(i, m - 1 - x[2]/n)printf("1");
	}
	else{
		rep(i, n)printf("0");
		rep(i, m - x[2] / n)printf("1");
	}
}

int main(){
	int Tc = 1;//; scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve(tc);
	}
	return 0;
}