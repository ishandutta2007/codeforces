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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;


void solve(){
	int n; scanf("%d", &n);
	printf("%d\n", (n-1) >> 1);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve();
	}
	return 0;
}