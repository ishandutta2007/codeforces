#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;
	int s1 = 0, q1 = 0, s2 = 0, q2 = 0;
	for (int i = 0; i < n/2; ++i) {
		if (str[i] == '?') ++q1;
		else s1 += str[i] - '0';
	}
	for (int i = n/2; i < n; ++i) {
		if (str[i] == '?') ++q2;
		else s2 += str[i] - '0';
	}
	if ((q1 + q2) % 2 == 1) {
		cout << "Monocarp" << '\n';
	} else {
		int s_diff = s1 - s2;
		int q_diff = q1 - q2;
		if (s_diff < 0) {
			s_diff *= -1;
			q_diff *= -1;
		}
		if (q_diff > 0) {
			cout << "Monocarp" << '\n';
		} else {
			if (s_diff == -q_diff / 2 * 9) {
				cout << "Bicarp" << '\n';
			} else {
				cout << "Monocarp" << '\n';
			}
		}
	}
}