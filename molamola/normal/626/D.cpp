#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int cnt[5050];
int p[2020], n;
ll cnt2[5050];

int main(){
	scanf("%d", &n);
	rep(i, n)scanf("%d", p+i);
	sort(p, p+n);
	rep(i, n)rep(j, i)cnt[p[i] - p[j]]++;
	for(int i=1;i<=5000;i++)cnt2[i] = cnt2[i-1] + cnt[i];
	int x = n * (n-1) / 2;
	ll ans = 0;
	for(int i=1;i<=5000;i++){
		if(!cnt[i])continue;
		for(int j=1;j<=i-1;j++)ans += (ll)cnt[i] * cnt[j] * cnt2[i-j-1];
	}
	printf("%.10f", ans / ((double)x * x * x));
	return 0;
}