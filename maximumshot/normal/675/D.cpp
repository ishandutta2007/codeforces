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
#include <math.h>
#include <unordered_map>
#include <array>

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

bool solve() {
	
	int n;
	scanf("%d", &n);

	vec< int > a(n), crd, h(n);
	set< pii > q;
	set< pii > :: iterator it, nxt, prv;

	for(int i = 0;i < n;i++) scanf("%d", &a[i]), crd.push_back(a[i]);

	sort(ALL(crd));

	h[0] = 1;
	q.insert(mp(a[0], 0));

	for(int val, pos, val2, pos2, i = 1;i < n;i++) {
		it = q.upper_bound(mp(a[i], i));
		if(it == q.end()) {
			prv = it;
			prv--;
			val = prv->first;
			pos = prv->second;
			printf("%d ", val);
			h[i] = h[pos] + 1;
		}else if(it == q.begin()) {
			nxt = it;
			val = nxt->first;
			pos = nxt->second;
			printf("%d ", val);
			h[i] = h[pos] + 1;
		}else {
			nxt = it;
			prv = it;
			prv--;

			val = nxt->first;
			pos = nxt->second;

			val2 = prv->first;
			pos2 = prv->second;

			if(h[pos] > h[pos2]) {
				printf("%d ", val);		
				h[i] = h[pos] + 1;
			}else {
				printf("%d ", val2);
				h[i] = h[pos2] + 1;
			}
		}

		q.insert(mp(a[i], i));
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}