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


int main() {
	string s1, s2;
	int n;
	cin >> s1 >> s2;
	cin >> n;
	cout << s1 << " " << s2 << "\n";
	for (int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		if (s1 == a)
			s1 = b;
		else
			s2 = b;
		cout << s1 << " " << s2 << "\n";
	}
	return 0;
}