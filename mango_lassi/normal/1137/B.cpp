#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// TCR
vector<int> zAlgo(const string& s) {
	int n=s.size();
	vector<int> z(n);
	int l=0;int r=0;
	for (int i=1;i<n;i++) {
		z[i]=max(0, min(z[i-l], r-i));
		while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r) {
			l=i;r=i+z[i];
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, pat;
	cin >> str >> pat;

	int m = str.size();
	int ones = 0;
	int zeroes = 0;
	for (int i = 0; i < m; ++i) {
		if (str[i] == '0') ++zeroes;
		if (str[i] == '1') ++ones;
	}

	vector<int> z = zAlgo(pat);
	int j = 1;
	int n = pat.size();
	for (; j < n; ++j) {
		if (j + z[j] >= n) break;
	}

	string res(m, '_');
	for (int i = 0; i < m; ++i) {
		char t = pat[i % j];
		if ((t == '0' && zeroes > 0) || ones == 0) {
			res[i] = '0';
			--zeroes;
		} else if ((t == '1' && ones > 0) || zeroes == 0) {
			res[i] = '1';
			--ones;
		}
	}
	cout << res << '\n';
}