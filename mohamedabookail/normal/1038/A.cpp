/**
 *    author:  Mohamed Abo_Okail
 *    created: 20/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n, k; string s;
	cin >> n >> k >> s;
	map < char, int > mp;
	int mn = 1e7;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}
	for (char i = 'A'; i < ('A' + k); i++) {
		mn = min(mn, mp[i]);
	}
	cout << mn * k << endl;
}