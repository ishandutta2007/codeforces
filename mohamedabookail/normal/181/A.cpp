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
	int n, m; cin >> n >> m;
	vector < pair < int, int > > v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch; cin >> ch;
			if(ch == '*') {
				v.push_back(make_pair(i, j));
			}
		}
	}
	if(v[1].first == v[2].first) {
		if(v[0].second == v[2].second) {
			cout << v[0].first << ' ' << v[1].second << endl;
		}
		else {
			cout << v[0].first << ' ' << v[2].second << endl;
		}
	}
	else {
		if(v[1].second == v[2].second) {
			cout << v[2].first << ' ' << v[0].second << endl;
		}
		else {
			cout << v[2].first << ' ' << v[1].second << endl;
		}
	}
	
}