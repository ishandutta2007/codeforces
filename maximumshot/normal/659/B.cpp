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

	int n, m;

	scanf("%d %d", &n, &m);

	vec< vec< pair< int, string > > > a(m + 1);
	
	char buff[20];
	for(int x, y, i = 0;i < n;i++) {
		scanf("%s %d %d", &buff, &x, &y);
		a[x].push_back(mp(y, buff));
	}

	for(int i = 1;i <= m;i++) {
		sort(ALL(a[i]));
		reverse(ALL(a[i]));
		if((int)a[i].size() == 2 || a[i][2].first < a[i][1].first) {
			cout << a[i][0].second << ' ' << a[i][1].second << '\n';
		}else cout << "?\n";
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}