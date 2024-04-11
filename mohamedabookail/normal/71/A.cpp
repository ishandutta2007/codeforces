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
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		if(s.size() > 10) {
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << o_o;
		}
		else { cout << s << o_o; }
	}
}