#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n, k, b, c;

	scanf("%d %d %d %d", &n, &k, &b, &c);

	b = min(b, c + c + c + c + c);

	vec< ll > t(n + 1);

	int mn = inf;
	for(int x, i = 1;i <= n;i++) {
		scanf("%d", &x);
		mn = min(mn, x);
		t[i] = x;
	}

	sort(t.begin() + 1, t.end());

	if(mn < 0) {
		int T = (4 - mn) / 5;
		for(int i = 1;i <= n;i++) t[i] += 5ll * T;
	}

	ll res = inf64, cur;

	for(int mod = 0;mod < 5;mod++) {
		multiset< ll > s;
		cur = 0;
		for(int i = 1;i <= n;i++) {
			ll tmp = 0;
			ll x = t[i];
			while(x % 5 != mod) x++, tmp++;
			tmp *= c;
			ll cost = b * (x / 5) - tmp;
			s.insert(cost);
			cur += cost;
			while((int)s.size() > k) {
				cur -= *s.begin();
				s.erase(s.begin());
			}
			if((int)s.size() == k) res = min(res, 1ll * k * b * (x / 5) - cur); 
		}
	}

	cout << res << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}