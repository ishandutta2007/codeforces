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

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

const int NMAX = 500500;
char buff[NMAX];

bool solve() {
	
	int n, a, b, TT;
	scanf("%d %d %d %d", &n, &a, &b, &TT);

	ll T = TT;

	scanf("%s", &buff);
	string s = buff;

	vec< int > pr(n), sf(n);

	for(int i = 0;i < n;i++) {
		if(i > 0) pr[i] = pr[i - 1] + a;
		if(s[i] == 'w') pr[i] += b;
		pr[i]++;
	}

	if(n == 1) {
		if(pr[n - 1] <= T) {
			printf("1\n");
		}else {
			printf("0\n");
		}
		return true;
	}

	sf[n - 1] = b * (s[0] == 'w') + 1 + a + b * (s[n - 1] == 'w') + 1;

	for(int i = n - 2;i > 0;i--) {
		sf[i] = sf[i + 1];
		sf[i] += a;
		if(s[i] == 'w') sf[i] += b;
		sf[i]++;
	}

	int ans = 0;

	for(int i = 0;i < n;i++) {
		if(pr[i] <= T) ans = max(ans, i + 1);
		if(i > 0 && sf[i] <= T) ans = max(ans, n - i + 1);
	}

	for(int i = 0;i < n;i++) sf[i] = 0;

	for(int i = n - 1;i > 0;i--) {
		if(i + 1 < n) sf[i] = sf[i + 1];
		sf[i] += a;
		if(s[i] == 'w') sf[i] += b;
		sf[i]++;
	}

	for(int j = n, i = n - 2;i >= 0;i--) {
		while(j - 1 > i && pr[i] + i * a + sf[j - 1] <= T) j--;
		if(j < n && pr[i] + i * a + sf[j]) ans = max(ans, i + 1 + n - j);
	}

	for(int i = 0;i < n;i++) {
		pr[i] = sf[i] = 0;
	}

	sf[n - 1] = b * (s[0] == 'w') + 1 + a + b * (s[n - 1] == 'w') + 1;

	for(int i = n - 2;i > 0;i--) {
		sf[i] = sf[i + 1];
		sf[i] += a;
		if(s[i] == 'w') sf[i] += b;
		sf[i]++;
	}

	for(int i = 1;i < n;i++) {
		pr[i] = pr[i - 1];
		pr[i] += a;
		if(s[i] == 'w') pr[i] += b;
		pr[i]++;
	}

	for(int j = 0, i = 1;i < n;i++) {
		while(j + 1 < i && sf[i] + (n - i) * a + pr[j + 1] <= T) j++;
		if(j > 0 && sf[i] + (n - i) * a + pr[j]) ans = max(ans, 1 + (n - i) + j);
	}

	printf("%d\n", ans);

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}