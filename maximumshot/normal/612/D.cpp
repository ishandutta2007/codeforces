#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, k;

	scanf("%d %d", &n, &k);

	vec< pii > a, q, ans;
	
	for(int l, r, i = 0;i < n;i++) {
		scanf("%d %d", &l, &r);
		a.push_back(mp(l, r));
		q.push_back(mp(l, 0));
		q.push_back(mp(r, 1));
	}
	
	sort(ALL(q));
	
	int cur = 0;

	for(int last = -inf - 1, i = 0;i < 2 * n;i++) {
		int j = i, op = 0, cl = 0;
		while(j < 2 * n && q[i].first == q[j].first) {
			if(q[j].second == 0) op++;
			else cl++;
			j++;
		}
		j--;
		if(cur + op >= k) {
			if(last == -inf - 1) last = q[i].first;
			
			if(cur - cl + op >= k) {}
			else {
				ans.push_back(mp(last, q[i].first));
				last = -inf - 1;
			}
		}
		cur = cur - cl + op;
		i = j;
	}

	printf("%d\n", (int)ans.size());
	for(auto i : ans) printf("%d %d\n", i.first, i.second);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}