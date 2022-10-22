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
#include <complex>

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

	vec< int > a(n + 1);
	
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	
	vec< int > d(n + 1, inf);

	d[1] = 0;
	queue< int > q;
	q.push(1);

	while(!q.empty()) {
		int v = q.front();
		q.pop();

		if(v > 1 && d[v - 1] > d[v] + 1) {
			d[v - 1] = d[v] + 1;
			q.push(v - 1);
		}

		if(v < n && d[v + 1] > d[v] + 1) {
			d[v + 1] = d[v] + 1;
			q.push(v + 1);
		} 

		if(v != a[v] && d[a[v]] > d[v] + 1) {
			d[a[v]] = d[v] + 1;
			q.push(a[v]);
		}
	}

	for(int i = 1;i <= n;i++) printf("%d ", d[i]);
	printf("\n");

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}