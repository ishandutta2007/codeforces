#include<bits/stdc++.h>
using namespace std;

int go() {
	string S; cin >> S;
	vector<pair<char, int>> freq;
	for (char c : S) {
		if (freq.empty() || freq.back().first != c) {
			freq.push_back({c, 0});
		}
		freq.back().second++;
	}

	if (freq.size() % 2 == 0) return 0;
	for (int i = 0, j = int(freq.size()) - 1; i < j; i++, j--) {
		if (freq[i].first != freq[j].first) return 0;
		if (freq[i].second + freq[j].second < 3) return 0;
	}
	if (freq[int(freq.size()) / 2].second + 1 < 3) {
		return 0;
	}
	return freq[int(freq.size()) / 2].second + 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << go() << '\n';

	return 0;
}