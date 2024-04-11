#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
string s;
int let[Maxl];
string typ;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            let[s[i] - 'a'] = i;
        int res = 0;
        cin >> typ;
        for (int i = 0; i + 1 < typ.length(); i++)
            res += abs(let[typ[i] - 'a'] - let[typ[i + 1] - 'a']);
        cout << res << endl;
    }
    return 0;
}