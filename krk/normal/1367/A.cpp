#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        cout << s[0];
        for (int i = 1; i < s.length(); i += 2)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}