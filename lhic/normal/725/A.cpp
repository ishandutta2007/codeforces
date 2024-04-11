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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] != '<')
			break;
		++cnt;
	}
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (s[i] != '>')
			break;
		++cnt;
	}
	cout << cnt << "\n";
	return 0;
}