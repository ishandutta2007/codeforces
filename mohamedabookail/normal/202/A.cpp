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
	string s; cin >> s;
	char ch = 'a';
	map < char, int > mp;
	for(auto it : s) {
		ch = max(ch, it);
		mp[it]++;
	}
	string str(mp[ch], ch);
	cout << str << endl;
}