/**
 *    author:  Mohamed Abo_Okail
 *    created: O5/O2/2O2O
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
	string a = "", b = "";
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		a += s[i];
		b += s[i + n];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		if(a[i] > b[i]) x++;
		if(a[i] < b[i]) y++;
	}
	cout << (x == n || y == n ? "YES" : "NO") << o_o;
}