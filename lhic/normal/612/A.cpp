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

int n, p, q;
string s;
vector<string> vv;

int main() {
	cin >> n >> p >> q;
	cin >> s;
	for (int a = 0; a <= 200; ++a)
		for (int b = 0; b < 200; ++b) {
			if (a * p + b * q == n) {
				int now = 0;
				for (int i = 0; i < a; ++i) {
					vv.push_back(s.substr(now, p));
					now += p;
				}
				for (int i = 0; i < b; ++i) {
					vv.push_back(s.substr(now, q));
					now += q;
				}
				cout << vv.size() << "\n";
				for (auto ss: vv)
					cout << ss << "\n";
				return 0;
			}
		}
	cout << -1 << "\n";
	return 0;
}