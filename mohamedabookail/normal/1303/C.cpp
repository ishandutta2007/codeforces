/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		string s; cin >> s;
		vector < pair < int, pair < char, char > > > v(27);
		for (int i = 0; i < 26; i++) {
			v[i].first = 0;
			v[i].second.first = 'a';
			v[i].second.second = 'a';
		}
		map < char, bool > mp;
		bool bol = 1;
		for (int i = 1; i < s.size() - 1; i++) {
			if(mp[s[i]]) {
				if(v[s[i] - 'a'].second.first == v[s[i] - 'a'].second.second) {
					if(v[s[i] - 'a'].second.first == s[i - 1]) {
						v[s[i] - 'a'].second.first = s[i + 1];
					}
					else if(v[s[i] - 'a'].second.first == s[i + 1]) {
						v[s[i] - 'a'].second.first = s[i - 1];
					}
					else {
						bol = 0;
						continue;
					}
				}
				string a = "", b = "", c = "", d = "", e = "";
				a += s[i - 1]; a += s[i + 1];
				b += v[s[i] - 'a'].second.first;
				b += v[s[i] - 'a'].second.second;
				c = b; reverse(c.begin(), c.end());
				d += v[s[i] - 'a'].second.first;
				d += v[s[i] - 'a'].second.first;
				e += v[s[i] - 'a'].second.second;
				e += v[s[i] - 'a'].second.second;
				if(a != b && a != c && a != d && a != e) {
					bol = 0;
					break;
				}
			}
			else {
				mp[s[i]] = 1;
				v[s[i] - 'a'].first = 1;
				v[s[i] - 'a'].second.first = s[i - 1];
				v[s[i] - 'a'].second.second = s[i + 1];
			}
		}
		if(!bol) cout << "NO" << o_o;
		else {
			string t = "";
			int xx = 1000;
			while(xx--) {
				for (int i = 0; i < 26; i++) {
					if(v[i].first) {
						if(!t.size()) {
							t += char(i + 'a');
							if(v[i].second.first == v[i].second.second) {
								t.push_back(v[i].second.first);
							}
							else {
								t.push_back(v[i].second.second);
								t = v[i].second.first + t;
							}
							v[i].first = 0;
						}
						else {
							if(v[i].second.first == v[i].second.second) {
								v[i].first = 0;
								if(t[0] == v[i].second.first) {
									if(t[1] != char(i + 'a')) {
										t = char(i + 'a') + t;
									}
								}
								else if(t[t.size() - 1] == v[i].second.first) {
									if(t[t.size() - 2] != char(i + 'a')) {
										t.push_back(char(i + 'a'));
									}
								}
								else {
									v[i].first = 1;
								}
							}
							else {
								v[i].first = 0;
								if(t[0] == v[i].second.first) {
									if(char(i + 'a') != t[1]) {
										t = char(i + 'a') + t;
										t = v[i].second.second + t;
									}
									else {
										if(t.size() == 2) {
											t.push_back(v[i].second.second);
										}
									}
								}
								else if(t[0] == v[i].second.second) {
									if(char(i + 'a') != t[1]) {
										t = char(i + 'a') + t;
										t = v[i].second.first + t;
									}
									else {
										if(t.size() == 2) {
											t.push_back(v[i].second.first);
										}
									}
								}
								else if(t[t.size() - 1] == v[i].second.first) {
									if(char(i + 'a') != t[t.size() - 2]) {
										t.push_back(char(i + 'a'));
										t.push_back(v[i].second.second);
									}
									else {
										if(t.size() == 2) {
											t = v[i].second.second + t;
										}
									}
								}
								else if(t[t.size() - 1] == v[i].second.second) {
									if(char(i + 'a') != t[t.size() - 2]) {
										t.push_back(char(i + 'a'));
										t.push_back(v[i].second.first);
									}
									else {
										if(t.size() == 2) {
											t = v[i].second.first + t;
										}
									}
								}
								else if(t[0] == char(i + 'a')) {
									if(t[1] == v[i].second.first) {
										t = v[i].second.second + t;
									}
									else {
										t = v[i].second.first + t;
									}
								}
								else if(t[t.size() - 1] == char(i + 'a')) {
									if(t[t.size() - 2] == v[i].second.first) {
										t.push_back(v[i].second.second);
									}
									else {
										t.push_back(v[i].second.first);
									}
								}
								else {
									v[i].first = 1;
								}
							}
						}
					}
				}
			}
			set < char > st;
			map < char, bool > _final;
			if(s.size() <= 2) t = s;
			for (int i = 0; i < t.size(); i++) {
				st.insert(t[i]);
				_final[t[i]] = 1;
			}
			if(t.size() != st.size()) cout << "NO" << o_o;
			else {
				cout << "YES" << o_o << t;
				for (char i = 'a'; i <= 'z'; i++) {
					if(!_final[i]) cout << i;
				}
				cout << o_o;
			}
		}
	}
}