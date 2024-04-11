/**
 *    author:  Mohamed Abo_Okail
 *    created: 29/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	string s; getline(cin, s);
	string t = "";
	map < int, bool > mp;
	int c = -1;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] != ' ') {
			t += s[i];
			c++;
		}
		else { mp[c] = true; }
	}
	for (int i = 0; i < t.size(); i++) {
		if(mp[i]) {
			if(t[i + 1] >= 'a' && t[i + 1] <= 'z') {
				cout << t[i] << ' ';
			}
			else { cout << t[i]; }
		}
		else {
			if(t[i] >= 'a' && t[i] <= 'z' || i + 1 == t.size()) {
				cout << t[i];
			}
			else { cout << t[i] << ' '; }
		}
	}
	cout << o_o;
}