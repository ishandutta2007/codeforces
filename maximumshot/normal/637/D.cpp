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
	
	int n, m, s, d;

	scanf("%d %d %d %d", &n, &m, &s, &d);

	vec< int > a(n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}

	sort(ALL(a));

	if(a[0] - 1 < s) {
		printf("IMPOSSIBLE\n");
		return true;
	}

	vec< pii > seg;
	vec< int > ans;
	
	seg.push_back(mp(-1, -1));

	for(int i = 0;i < n;i++) {
		int j = i + 1;
		while(j < n && a[j] - a[j - 1] - 1 < s + 1) j++; 
		j--;
		seg.push_back(mp(a[i], a[j]));
		i = j;
	}

	for(int p, i = 1;i < (int)seg.size();i++) {
	
		p = seg[i - 1].second + 1;
		if(p + s >= seg[i].first) {
			printf("IMPOSSIBLE\n");
			return true;
		}
		p = seg[i].first - 1;
		if(p + d <= seg[i].second) {
			printf("IMPOSSIBLE\n");
			return true;
		}
	}

	for(int p, dist, i = 1;i < (int)seg.size();i++) {
		
		p = seg[i - 1].second + 1;
		dist = seg[i].first - 1 - p;
		printf("RUN %d\n", dist);
		p = seg[i].first - 1;
		dist = seg[i].second + 1 - p;
		printf("JUMP %d\n", dist);
	}

	if(seg.back().second + 1 < m) 
		printf("RUN %d\n", m - (seg.back().second + 1));

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}