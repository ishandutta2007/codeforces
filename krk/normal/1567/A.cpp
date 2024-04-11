#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'U') cout << 'D';
            else if (s[i] == 'D') cout << 'U';
            else cout << s[i];
        cout << "\n";
    }
    return 0;
}