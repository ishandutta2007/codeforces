/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	string s; cin >> s;
	map < char, int > mp;
	for (int i = 0; i < s.size(); i++) {
		mp[s[i]]++;
	}
	if(mp['4'] + mp['7'] == 4 || mp['4'] + mp['7'] == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}