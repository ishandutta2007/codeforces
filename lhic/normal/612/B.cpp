#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

int n;
int go[300000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		--a;
		go[a] = i;
	}
	ll sum = 0;
	for (int i = 0; i < n - 1; ++i)
		sum += abs(go[i] - go[i + 1]);
	cout << sum << "\n";
	return 0;
}