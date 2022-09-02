#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
typedef long double ld;
typedef long long ll;

const int C = 26;
vector<int> apps[C];
int cou[C];

int main() {
	string str;
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; ++i) {
		apps[str[i]-'a'].push_back(i);
	}
	
	int res = 0;
	for (int c = 0; c < C; ++c) {
		int ans = 0;
		for (int x = 1; x < n; ++x) {
			for (int j = 0; j < C; ++j) cou[j] = 0;
			for (auto i : apps[c]) {
				++cou[str[(i + x)%n] - 'a'];
			}
			int sub = 0;
			for (int j = 0; j < C; ++j) {
				if (cou[j] == 1) ++sub;
			}
			ans = max(ans, sub);
		}
		res += ans;
	}
	cout << fixed << setprecision(20) << ((ld)res / n) << '\n';
}