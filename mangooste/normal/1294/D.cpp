#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, x;
	cin >> q >> x;
	vector<int> cnt(x, 0);
	set<pair<int, int>> st;
	for (int i = 0; i < x; i++)
		st.emplace(0, i);
	while (q--) {
		int el;
		cin >> el;
		el %= x;
		st.erase({cnt[el], el});
		cnt[el]++;
		st.emplace(cnt[el], el);
		pair<int, int> mn = *st.begin();
		cout << x * mn.first + mn.second << '\n';
	}
}