#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
	if (s[i] <= '4' || i == 0 && s[i] == '9')
	    cout << s[i];
	else
	    cout << char(9 - (s[i] - '0') + '0');	
    cout << endl;
    return 0;
}