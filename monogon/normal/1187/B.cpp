
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int n, m;
string s, t;
int pos[MAX_N][26], c[26];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> m;
    for(int j = 0; j < 26; j++) {
        pos[0][j] = 0;
        for(int i = 1; i < n; i++) {
            pos[i][j] = n;
        }
    }
    for(int i = 0; i < n; i++) {
        c[s[i] - 'a']++;
        pos[c[s[i] - 'a']][s[i] - 'a'] = i + 1;
    }

    for(int i = 0; i < m; i++) {
        cin >> t;
        fill(c, c + 26, 0);
        int M = 0;
        for(int j = 0; j < t.length(); j++) {
            c[t[j] - 'a']++;
            M = max(M, pos[c[t[j] - 'a']][t[j] - 'a']);
        }
        cout << M << endl;
    }
}