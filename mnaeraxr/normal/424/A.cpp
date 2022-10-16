#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int u = 0, d = 0;
	for (int i = 0; i < n; ++i){
		if (s[i] == 'x') ++d;
		else ++u;
	}	

	int t = abs(u - n / 2);
	cout << t << endl;
	for (int i = 0; i < n; ++i){
		if (s[i] == 'x' && d > u){
			s[i] = 'X';
			d--;
			u++;
		}
		else if (s[i] == 'X' && u > d){
			s[i] = 'x';
			u--;
			d++;
		}
	}
	cout << s << endl;
}