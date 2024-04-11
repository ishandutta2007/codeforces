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

	int n, b;

	scanf("%d %d", &n, &b);

	vec< ll > t(n), d(n);

	for(int i = 0;i < n;i++) {
		cin >> t[i] >> d[i];
	}
	
	ll now = 0;
	vec< ll > ans(n, -1);
	
	queue< int > q;

	for(int i = 0;i < n;) {
		q.push(i++);
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			now = max(now, t[v]);
			ans[v] = now + d[v];
			while(i < n && t[i] < now + d[v]) {
				if((int)q.size() < b) q.push(i++);
				else ans[i++] = -1;
			}
			now += d[v];
		}
	}

	for(int i = 0;i < n;i++) {
		cout << ans[i] << ' '; 
	}

	printf("\n");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}