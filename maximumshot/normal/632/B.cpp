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

const int N = 500500;
char buffer[N];

bool solve() {
		
	int n;
	scanf("%d", &n);

	vec< int > p(n);
	for(int i = 0;i < n;i++) scanf("%d", &p[i]);

	scanf("%s", &buffer); 
	
	string s = buffer;

	vec< ll > all(2); 

	for(int i = 0;i < n;i++) {
		all[s[i] - 'A'] += p[i];
	}

	ll ans = all[1];

	for(int it = 0;it < 2;it++) {
		vec< ll > sum(2);
		for(int i = 0;i < n;i++) {
			sum[s[i] - 'A'] += p[i];
			ans = max(ans, all[1] - sum[1] + sum[0]);
		}
		reverse(ALL(s));
		reverse(ALL(p));
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}