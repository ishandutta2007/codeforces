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

const int VALMAX = 2 * 1000100;

bool solve() {

	vec< char > prime(VALMAX, 1);

	prime[0] = prime[1] = 0;

	for(int i = 2;i * i < VALMAX;i++) {
		if(!prime[i]) continue;
		for(int j = i * i;j < VALMAX;j += i) prime[j] = 0;
	}

	int n;
	scanf("%d", &n);

	vec< int > a(n + 1);

	int c1 = 0, pr = -1;

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		if(a[i] == 1) c1++;
		if(prime[a[i] + 1] && a[i] > 1) pr = a[i];
	}

	if(c1 >= 2) {
		printf("%d\n", c1 + (pr != -1));
		for(int i = 0;i < c1;i++) printf("1 ");
		if(pr != -1) printf("%d\n", pr);
		return true;
	}

	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			if(prime[a[i] + a[j]]) {
				printf("2\n%d %d\n", a[i], a[j]);
				return true;
			}
		}
	}

	printf("1\n%d\n", a[1]);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}