/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; string s;
	cin >> n >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '0') { a++; }
		else { b++; }
	}

	if(a != b) { cout << 1 << endl << s << endl; }
	else {
		cout << 2 << endl << s[0] << ' ';
		for (int i = 1; i < n; i++) {
			cout << s[i];
		} cout << endl;
	}
}