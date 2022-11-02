#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

string s, t;
int freq1[200], freq2[200], am[200];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> s >> t;
    for (int i=0; i<s.length(); i++)
        freq1[s[i]] ++, am[s[i]] ++;
    for (int i=0; i<t.length(); i++)
        freq2[t[i]] ++;

    int ans = 0;
    for (int i='A'; i<='Z'; i++)
        ans += abs(freq1[i] - freq2[i]);
    ans /= 2;

    cout << ans << '\n';

    for (int i=0; i<s.length(); i++) {
        am[s[i]]--;
        if (freq1[s[i]] > freq2[s[i]])
            for (char c='A'; c<='Z'; c++)
                if (freq1[c] < freq2[c]) {
                    if (c > s[i] && am[s[i]] >= freq1[s[i]] - freq2[s[i]]) break;
                    freq1[s[i]] --;
                    s[i] = c;
                    freq1[s[i]] ++;
                    break;
                }
    }
    cout << s << '\n';
    return 0;
}