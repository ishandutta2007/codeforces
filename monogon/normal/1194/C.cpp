
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
string s, t, p;
int ltr[26];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> s >> t >> p;
        // check s subsequence t and count letters of t not in s.
        fill(ltr, ltr + 26, 0);
        int i = 0;
        for(int j = 0; j < t.length(); j++) {
            if(i < s.length() && s[i] == t[j])
                i++;
            else
                ltr[t[j] - 'a']++;
        }
        if(i < s.length()) {
            cout << "NO" << endl;
            goto endloop;
        }
        for(int j = 0; j < p.length(); j++) {
            ltr[p[j] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(ltr[i] > 0) {
                cout << "NO" << endl;
                goto endloop;
            }
        }
        cout << "YES" << endl;
        endloop:;
    }
}