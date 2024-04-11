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
#include <unordered_map>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

void solve(){
	int L = -2e9, H = 2e9;
	int n; scanf("%d", &n);
	int s = 0;
	rep(i, n){
		int c, d; scanf("%d%d", &c, &d);
		if(d == 1){
			L = max(L, 1900 - s);
		}
		else{
			H = min(H, 1899 - s);
		}
		s += c;
	}
	if(L > H){
		puts("Impossible");
	}
	else{
		if(H == 2e9){
			puts("Infinity");
		}
		else{
			printf("%d", H + s);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}