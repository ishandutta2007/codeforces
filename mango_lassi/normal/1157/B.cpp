#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int M = 10;
int tar[M];

char digMap(char c) {
	return tar[c - '0'] + '0';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	for (int i = 1; i < M; ++i) {
		cin >> tar[i];
	}

	bool act = false;
	for (int i = 0; i < str.size(); ++i) {
		if (digMap(str[i]) > str[i]) {
			act = true;
			str[i] = digMap(str[i]);
		} else if (digMap(str[i]) == str[i]) {
			continue;
		} else {
			if (act) break;
		}
	}
	cout << str << '\n';
}