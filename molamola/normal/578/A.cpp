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

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;

ll x, y;

int main() {
	scanf("%lld%lld",&x,&y);
	double ans = 1e12;
	if(x == y)ans = x;
	if(x >= y * 3){
		ll k = (x - y) / 2 / y;
		ans = min(ans, (double)(x-y)/2.0/k);
	}
	if(x > y){
		ll k = (x+y) / 2 / y;
		ans = min(ans, (double)(x+y)/2.0/k);
	}
	if(ans < 1e12)printf("%.10lf",ans);
	else printf("-1");
	return 0;
}