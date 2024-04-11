#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool is_upper(char c) {
	return ('A' <= c && c <= 'Z');
}

char to_lower(char c) {
	if (is_upper(c)) {
		return c - 'A' + 'a';
	} else {
		return c;
	}
}

string to_lower(string s) {
	string result = "";
	for (int i = 0; i < s.size(); i++) {
		result += to_lower(s[i]);
	}
	// cerr << s << " " << result << "\n"; 
	return result;
}

int n;
map<string, int> f;

void solve() {
	cin >> n;
	f["polycarp"] = 1;
	for (int i = 0; i < n; i++) {
		string name1, tmp, name2; 
		cin >> name1 >> tmp >> name2;
		name1 = to_lower(name1);
		name2 = to_lower(name2);
		f[name1] = f[name2] + 1;
	}
	int answer = 0;
	for (auto pair : f) {
		answer = max(answer, pair.second);
	}
	cout << answer << "\n";
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}