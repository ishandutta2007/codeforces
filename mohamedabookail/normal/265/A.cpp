/**
 *    author:  Mohamed Abo_Okail
 *    created: 25/O1/2O2O
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
	string s, t; cin >> s >> t;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		bool bol = 0;
		for (int j = cnt; j < t.size(); j++) {
			if(s[i] == t[j]) {
				bol = 1;
				cnt = j + 1;
				break;
			}
		}
		if(!bol) {
			cout << i + 1 << o_o;
			break;
		}
	}
}