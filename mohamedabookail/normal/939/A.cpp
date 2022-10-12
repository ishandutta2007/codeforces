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
	int n; cin >> n;
	vector < int > v(n);
	map < int, int > mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[i + 1] = v[i];
	}
	for (int i = 0; i < n; i++) {
		if(mp[mp[mp[v[i]]]] == v[i]) {
			return cout << "YES" << endl, 0;
		}
	}
	cout << "NO" << endl;
}