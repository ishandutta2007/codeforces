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
	
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	int res = 0;

	list< int > l;
	list< int > :: iterator it;

	for(int x, i = 0;i < k;i++) {
		scanf("%d", &x);
		l.push_back(x);
	}

	for(int x, i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			scanf("%d", &x);
			it = l.begin();
			res++;
			while(*it != x) it++, res++;
			l.erase(it);
			l.push_front(x);
		}		
	}

	printf("%d\n", res);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}