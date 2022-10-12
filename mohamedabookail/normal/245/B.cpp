/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	string s; cin >> s;
	bool a = 1, b = 1;
	int c = 0;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if(s[i] == 'p') { c++; }
		if(s[i] == 'p' && a) {
			cout << "://";
			a = 0;
		}
		if(s[i + 1] == 'r' && s[i + 2] == 'u' && b && (s[i] != 'p' || c > 1)) {
			cout << ".ru";
			b = 0;
			i += 2;
			if(i < s.size() - 1) { cout << '/'; }
		}
	}
	cout << endl;
}