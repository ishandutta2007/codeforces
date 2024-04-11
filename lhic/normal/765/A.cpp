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
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		if (t.substr(0, 3) == s)
			++cnt;
		else
			--cnt;
	}
	if (cnt > 0)
		cout << "contest\n";
	else
		cout << "home\n";
	return 0;
}