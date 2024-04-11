
#include <iostream>
#include <set>

using namespace std;

int n, k, a[200000], t[200000];
set<int> s;
set<pair<int, int> > s2; // (skill, index)

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(i);
		s2.insert(make_pair(a[i], i));
	}
	// 0 if team 1, 1 if team 2
	bool b = 0;
	while(!s.empty()) {
		// iterator of student with max skill
		auto it = prev(s2.end());
		int i = it->second;
		t[i] = b ? 2 : 1;
		auto it2 = s.find(i);
		auto it3 = next(it2);
		for(int j = 0; j < k && it3 != s.end(); j++) {
			int idx = *it3;
			t[idx] = b ? 2 : 1;
			s2.erase(make_pair(a[idx], idx));
			s.erase(it3);
			it3 = next(it2);
		}
		for(int j = 0; j < k && it2 != s.begin(); j++) {
			it3 = prev(it2);
			int idx = *it3;
			t[idx] = b ? 2 : 1;
			s2.erase(make_pair(a[idx], idx));
			s.erase(it3);
		}
		s2.erase(it);
		s.erase(it2);
		b = !b;
	}
	for(int i = 0; i < n; i++) {
		cout << t[i];
	}
}