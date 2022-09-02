#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;
const int N = 50;

int dist(char a, char b) {
	return min(abs(a-b), 26 - abs(a-b));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	string tar = "ACTG";

	int res = INF;
	for (int i = 0; i+3 < str.size(); ++i) {
		int offer = 0;
		for (int j = 0; j < 4; ++j) {
			offer += dist(tar[j], str[i+j]);
		}
		res = min(res, offer);
	}
	cout << res << '\n';
}