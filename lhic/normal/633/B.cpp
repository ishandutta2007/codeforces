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

vector<int> ans;
int m;

int main() {
	int now = 0;
	cin >> m;
	for (int i = 1; ; ++i) {
		int x = i;
		while (x % 5 == 0)
			++now, x /= 5;
		if (now == m)
			ans.push_back(i);
		if (now > m)
			break;
	}
	cout << ans.size() << "\n";
	for (int i: ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}