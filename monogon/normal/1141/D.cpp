
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
string l, r;
set<pair<int, int> > s, s2, unpaired;
vector<pair<int, int> > pairs;

int main() {
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++) {
		if(l[i] == '?') {
			s.insert(make_pair(26, i));
		}else s.insert(make_pair(l[i] - 'a', i));
		if(r[i] == '?') {
			s2.insert(make_pair(26, i));
		}else s2.insert(make_pair(r[i] - 'a', i));
	}
	for(pair<int, int> p : s) {
		if(p.first < 26) {
			auto it = s2.lower_bound(make_pair(p.first, 0));
//			cout << p.first << ": " << it->first << " " << it->second << endl;
			if(it != s2.end() && p.first == it->first) {
				pairs.push_back(make_pair(p.second + 1, it->second + 1));
				s2.erase(it);
			}else {
				unpaired.insert(p);
			}
		}else if(s2.begin()->first < 26) {
			pairs.push_back(make_pair(p.second + 1, s2.begin()->second + 1));
			s2.erase(s2.begin());
		}else {
			unpaired.insert(p);
		}
	}
	for(pair<int, int> p : s2) {
		if(p.first == 26 && !unpaired.empty()) {
			pairs.push_back(make_pair(unpaired.begin()->second + 1, p.second + 1));
			unpaired.erase(unpaired.begin());
		}
	}
	cout << pairs.size() << endl;
	for(pair<int, int> p : pairs) {
		cout << p.first << " " << p.second << endl;
	}
}