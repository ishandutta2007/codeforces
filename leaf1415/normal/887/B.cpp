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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[3][6];
ll p[3];
set<ll> S;

void dfs(int k, int x)
{
	if(k == n){
		S.insert(x);
		return;
	}

	dfs(k+1, x);
	rep(i, 0, 5) dfs(k+1, x*10+a[p[k]][i]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 0, n-1) rep(j, 0, 5) cin >> a[i][j];
	rep(i, 0, n-1) p[i] = i;

	do{
		dfs(0, 0);
	}while(next_permutation(p, p+3));

	rep(i, 1, 10000){
		if(S.count(i) == 0){
			cout << i-1 << endl;
			break;
		}
	}

	return 0;
}