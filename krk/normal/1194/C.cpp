#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
string s, t, p;
int freq[Maxl];

bool Check()
{
    int pnt = 0;
    for (int i = 0; i < t.length(); i++) {
        if (pnt < s.length() && t[i] == s[pnt]) pnt++;
        else if (--freq[t[i] - 'a'] < 0) return false;
    }
    return pnt >= s.length();
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        cin >> t;
        cin >> p;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < p.length(); i++)
            freq[p[i] - 'a']++;
        printf("%s\n", Check()? "YES": "NO");
    }
    return 0;
}