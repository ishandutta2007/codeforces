#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;


llint n;

llint fact(llint x)
{
	llint ret = 1;
	rep(i, 1, x) ret *= i;
	return ret;
}

llint comb(llint n, llint k)
{
	return fact(n) / fact(k) / fact(n-k);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint ans = comb(n-1, n/2-1);
	ans *= fact(n/2-1) * fact(n/2-1);
	cout << ans << endl;
	
	return 0;
}