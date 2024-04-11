/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O2/2O2O
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
	int n; string s; cin >> n >> s;
	string t = ""; t += s[0];
	for (int i = 1; i < n; i++) {
		if(i % 2) {
			t = (s[i] + t);
		}
		else {
			t += s[i];
		}
	}
	if(!(n % 2)) reverse(t.begin(), t.end());
	cout << t << o_o;
}