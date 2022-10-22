#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

//#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
	os.precision(10);
	os << fixed;
	os << "{";
	os << a.first;
	os << ' ';
	os << a.second;
	os << "} "; 
	return os;
}

LL cnt[200000 + 10], all[200000 + 10], vis[200000 + 10];

void dfs(LL i, LL x, LL c = 0) {
	if(vis[x] == i || x >= 2e5 + 10) return;
	all[x]++;
	cnt[x] += c;
	vis[x] = i;
	if(x == 0) return;
	dfs(i, 2 * x, c + 1);
	dfs(i, x / 2, c + 1);
}

bool solve() {

	int n;
	cin >> n;

	LL x, y, c;

	for(int i(0);i < n;i++) {
		cin >> x;
		dfs(i + 1, x);
	}

	LL ans = inf64;

	for(int i(0);i <= 2e5;i++) {
		if(all[i] == n) {
			ans = min(ans, cnt[i]);
		}
	}

	cout << ans << '\n';

	return true;
}

int main() 
{
	//while(solve());
	solve();

	return 0;
}