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
	
	char a[1000100];
	char b[1000100];

	scanf("%s %s", &a, &b);

	int i, j, n, m;
	i = j = 0;

	n = strlen(a);
	m = strlen(b);

	while(i < n && a[i] == '0') i++;
	if(i == n) i--;
	while(j < m && b[j] == '0') j++;
	if(j == m) j--;

	if(n - i < m - j) cout << '<';
	else if(n - i > m - j) cout << '>';
	else {
		for(int q = 0;q < n - i;q++) {
			if(a[i + q] > b[j + q]) {
				cout << '>';
				return true;
			}else if(a[i + q] < b[j + q]) {
				cout << '<';
				return true;
			}
		}
		cout << '=';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}