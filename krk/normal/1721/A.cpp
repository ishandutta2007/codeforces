#include <bits/stdc++.h>
using namespace std;

int T;
string s;
set <char> S;

int main()
{
    cin >> T;
    while (T--) {
        s = "";
        string a, b; cin >> a >> b;
        s = a + b;
        S.clear();
        for (int i = 0; i < s.length(); i++)
            S.insert(s[i]);
        cout << S.size() - 1 << endl;
    }
    return 0;
}