/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
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
	string a, b, c; cin >> a >> b >> c;
	map < char, char > mp;
	for (int i = 0; i < 26; i++) {
		mp[a[i]] = b[i];
	}
	for (int i = 0; i < c.size(); i++) {
		if(c[i] < '0' || c[i] > '9') {
			if(c[i] >= 'A' && c[i] <= 'Z') {
				char ch = tolower(c[i]);
				c[i] = toupper(mp[ch]);
			}
			else {
				c[i] = mp[c[i]];
			}
		}
	}
	cout << c << o_o;
}