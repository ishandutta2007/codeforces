#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int C = 26;

int main() {
	string in;
	cin >> in;

	int n = in.size();
	vector<string> str(3);

	int ss = 1;
	for (int j = 0; j < 3; ++j) {
		str[j].resize(n);
		for (int i = 0; i < n; ++i) {
			str[j][i] = 'a' + ((i / ss) % C);
		}
		ss *= C;
	}

	cout << "? " << str[0] << endl;
	cout << "? " << str[1] << endl;
	cout << "? " << str[2] << endl;

	vector<string> ans(3);
	for (int j = 0; j < 3; ++j) cin >> ans[j];

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = (ans[0][i]-'a') + 26 * (ans[1][i] - 'a') + 26*26 * (ans[2][i] - 'a');
	}

	string res(n, '_');
	for (int i = 0; i < n; ++i) res[perm[i]] = in[i];
	cout << "! " << res << endl;
}