/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	string s; cin >> s;
	map < char, int > mp;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		mp[s[i]]++;
		if(i < n / 2) a += s[i] - '0';
		else b += s[i] - '0';
	}
	cout << (a == b && mp['4'] + mp['7'] == n ? "YES" : "NO") << endl;
}