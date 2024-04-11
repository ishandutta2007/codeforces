#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string solve(const string& s) { 
    //cerr << s << endl;
	set<int> ds;
	set<int> rs;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'D')
			ds.insert(i);
		else
			rs.insert(i);
	if (ds.size() == 0)
		return "R";
	if (rs.size() == 0)
		return "D";
	string res;
	set<int> removed;
	for (int i = 0; i < s.length(); i++) {
		if (removed.count(i))
			continue;
		if (s[i] == 'R') {
			auto it = ds.upper_bound(i);
			if (it != ds.end()) {
				removed.insert(*it);
				ds.erase(it);
			} else {
				it = ds.begin();
				if (it != ds.end()) {
					removed.insert(*it);
					ds.erase(it);
				}
			}
		} else {
			auto it = rs.upper_bound(i);
			if (it != rs.end()) {
				removed.insert(*it);
				rs.erase(it);
			} else {
				it = rs.begin();
				if (it != rs.end()) {
					removed.insert(*it);
					rs.erase(it);
				}
			}
		}
	}
    for (int i = 0; i < s.length(); i++)
        if (!removed.count(i))
            res += s[i];
	return solve(res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int foo;
    cin >> foo;
	string s;
	cin >> s;
	cout << solve(s) << endl;
}