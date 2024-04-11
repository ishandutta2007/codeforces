#include <bits/stdc++.h>

using namespace std;

int k, cnt;
string s;
bool done[30];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> k >> s;
    for (int i=0; i<s.length(); i++) {
        int j = s.length()-1-i;
        if (s[i] == '?') {
            if (s[j] == '?' && j<=i) cnt++;
            continue;
        }
        if (s[j] != '?') {
            if (s[j] != s[i]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            } else done[s[i]-'a'] = 1;
        } else s[j] = s[i], done[s[i]-'a'] = 1;
    }
    int need = 0;
    for (int i=0; i<k; i++)
        if (!done[i])
            need++;
    if (need > cnt) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int p = 0;
    for (int i=0; i<s.length(); i++) {
        int j = s.length()-1-i;
        if (s[i] == '?') {
            assert(s[j] == '?');
            if (cnt > need) s[i] = s[j] = 'a', cnt--;
            else {
                while (p<k && done[p]) p++;
                s[i] = s[j] = p + 'a';
                done[p] = 1;
            }
        }
    }
    cout << s << '\n';
    return 0;
}