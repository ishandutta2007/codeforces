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
typedef long double ld;

using namespace std;


int ans[1000];
int main() {
	int n;
	cin >> n;
	int now = 1;
	while (n > 0) {
		int k = n % 10;
		for (int i = 0; i < k; ++i)
			ans[i] += now;
		now *= 10;
		n /= 10;
	}
	int fl = 0;
	for (int i = 0; i < 100; ++i)
		if (ans[i])
			fl = i;
	cout << fl + 1 << "\n";
	for (int i = 0; i <= fl; ++i)
		cout << ans[i] << " ";
	return 0;
}