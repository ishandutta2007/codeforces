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
	string sa, sb;
	cin >> sa >> sb;
	
	vector<int> zo, oz;
	for (int i = 0; i < n; ++i) {
		if (sa[i] == 'a' && sb[i] == 'b') oz.push_back(i);
		else if (sa[i] == 'b' && sb[i] == 'a') zo.push_back(i);
	}
	if ((zo.size() + oz.size()) % 2 == 1) {
		cout << -1 << '\n';
	} else {
		cout << (zo.size() + 1) / 2 + (oz.size() + 1) / 2 << '\n';
		while(zo.size() >= 2) {
			int i = zo.back();
			zo.pop_back();
			int j = zo.back();
			zo.pop_back();
			cout << i+1 << ' ' << j+1 << '\n';
		}
		while(oz.size() >= 2) {
			int i = oz.back();
			oz.pop_back();
			int j = oz.back();
			oz.pop_back();
			cout << i+1 << ' ' << j+1 << '\n';
		}
		if (! zo.empty()) {
			cout << zo[0]+1 << ' ' << zo[0]+1 << '\n';
			cout << zo[0]+1 << ' ' << oz[0]+1 << '\n';
		}
	}
}