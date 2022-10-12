/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	vector <string> v(n);
	bool b = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if(s[0] == 'O' && s[1] == 'O' && !b) {
			s[0] = '+'; s[1] = '+';
			b = 1;
		}
		if(s[3] == 'O' && s[4] == 'O' && !b) {
			s[3] = '+'; s[4] = '+';
			b = 1;
		}
		v[i] = s;
	}

	if(b) { 
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << v[i] << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}