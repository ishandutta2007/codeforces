#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int t;
string s;
int freq[Maxl];
int res;

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        freq[s[0] - 'a']++;
    }
    for (int i = 0; i < Maxl; i++) {
        int a = freq[i] / 2;
        res += a * (a - 1) / 2;
        a = freq[i] - a;
        res += a * (a - 1) / 2;
    }
    cout << res << endl;
    return 0;
}