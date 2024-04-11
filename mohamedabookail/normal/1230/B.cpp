/**
 *    author:  Mohamed.Abo_Okail
 *    created: 26/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if(n == 1) {
		if(k == 1) { cout << 0 << endl; }
		else { cout << s << endl; }
	}
	else {
		if(s[0] != '1' && k > 0) {
			s[0] = '1';
			k--;
		}
		for (int i = 1; i < n; i++) {
			if(s[i] != '0' && k > 0) {
				s[i] = '0';
				k--;
			}
		}
		cout << s << endl;
	}
}