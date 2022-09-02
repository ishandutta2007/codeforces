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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int P[100010];

void solve(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int x; scanf("%d", &x);P[x]++;
	}
	int ans = 0;
	for(int i=2;i<=100000;i++){
		int cnt = 0;
		for(int j=i;j<=100000;j+=i)cnt += P[j];
		ans = max(ans, cnt);
	}
	printf("%d", max(1, ans));
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}