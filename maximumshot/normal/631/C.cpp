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
	
	int n, m;

	scanf("%d %d", &n, &m);

	vec< int > a(n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	vec< pii > q;

	for(int t, r, i = 0;i < m;i++) {
		scanf("%d %d", &t, &r);
		while(!q.empty() && q.back().first <= r) q.pop_back();
		q.push_back(mp(r, t));
	}

	int last = -1;
	
	deque< int > dq;
	for(int i = 0;i < q[0].first;i++) dq.push_back(a[i]);
	sort(ALL(dq));
	
	for(int i = 0;i < (int)q.size();i++) {
		last = i;
		int l, r;
		if(i + 1 == (int)q.size()) l = 0, r = q[i].first - 1;
		else l = q[i + 1].first, r = q[i].first - 1;
		if(q[i].second == 1) {
			for(int j = r;j >= l;j--) a[j] = dq.back(), dq.pop_back();
		}else {
			for(int j = r;j >= l;j--) a[j] = dq.front(), dq.pop_front();
		}
	}

	for(int i = 0;i < n;i++) printf("%d ", a[i]);
	printf("\n");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}