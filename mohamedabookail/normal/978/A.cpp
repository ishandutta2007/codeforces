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
	stack < int > st;
	map < int, int > mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		mp[v[i]]++;
		if(mp[v[i]] == 1) {
			st.push(v[i]);
		}
	}
	cout << st.size() << endl;
	while(!st.empty()) {
		cout << st.top();
		st.pop();
		if(st.size()) { cout << ' '; }
	}
}