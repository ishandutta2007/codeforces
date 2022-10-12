/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
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
	int n; cin >> n; n--;
	string s = "";
	for (int i = 1; i < 400; i++) {
		string t = "";
		int cnt = i;
		while(cnt) {
			t += ((cnt % 10) + '0');
			cnt /= 10;
		}
		reverse(t.begin(), t.end());
		s += t;
	}
	cout << s[n] << o_o;
}