/**
*    author:  Mohamed Abo Okail
*    created: 2O/O9/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		set < char > st;
		for (int i = 0; i < 4; i++) {
			char ch;
			cin >> ch;
			st.insert(ch);
		}
		if(sz(st) == 1) {
			cout << 0 << endl;
		}
		else if(sz(st) == 2) {
			cout << 1 << endl;
		}
		else if(sz(st) == 3) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
}