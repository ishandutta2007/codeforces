#include <bits/stdc++.h>

using namespace std;

string s, a, b;
int k, n;

int get_from(int mask, int pos) {
    for (int i = pos; i < k; ++i) if (mask >> i & 1) return i;
    return k;
}
int get_til(int mask, int pos) {
    for (int i = pos; i >= 0; --i) if (mask >> i & 1) return i;
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> k >> s >> a >> b;
        char c = 'a' - 1 + k;
        n = s.size();
        int ptr = a.size() - 1, _flaga = 0, _flagb = 0;
        while (ptr >= 0 && a[ptr] == 'a') a[ptr] = c, --ptr;
        if (ptr < 0) _flaga = 1;
        else --a[ptr];
        ptr = b.size() - 1;
        while (ptr >= 0 && b[ptr] == c) b[ptr] = 'a', --ptr;
        if (ptr < 0) _flagb = 1;
        else ++b[ptr];

        int found = 0;
        for (int prio = 0; prio < 2; ++prio) {
            char p[27];
            for (int i = 0; i < k; ++i) p[i] = '$'; p[k] = 0;
            int unused = (1 << k) - 1;
            int no = 0, flaga = _flaga, flagb = _flagb;
            for (int i = 0; i < n; ++i) {
                if (flaga && flagb) break;
                else if (flaga) {
                    if (p[s[i] - 'a'] == '$') {
                        int op = get_from(unused, 0);
                        unused ^= 1 << op;
                        p[s[i] - 'a'] = 'a' + op;
                    }
                    if (p[s[i] - 'a'] > b[i]) {
                        no = 1;
                        break;
                    }
                    else if (p[s[i] - 'a'] < b[i]) flagb = 1;
                }
                else if (flagb) {
                    if (p[s[i] - 'a'] == '$') {
                        int op = get_til(unused, 25);
                        unused ^= 1 << op;
                        p[s[i] - 'a'] = 'a' + op;
                    }
                    if (p[s[i] - 'a'] < a[i]) {
                        no = 1;
                        break;
                    }
                    else if (p[s[i] - 'a'] > a[i]) flaga = 1;
                }
                else {
                    if (p[s[i] - 'a'] == '$') {
                        int op = get_from(unused, a[i] - 'a' + 1);
                        if (op + 'a' >= b[i])
                            op = prio ? get_from(unused, a[i] - 'a') : get_til(unused, b[i] - 'a');
                        unused ^= 1 << op;
                        p[s[i] - 'a'] = 'a' + op;
                    }
                    if (p[s[i] - 'a'] < a[i] || p[s[i] - 'a'] > b[i]) {
                        no = 1;
                        break;
                    }
                    if (p[s[i] - 'a'] > a[i]) flaga = 1;
                    if (p[s[i] - 'a'] < b[i]) flagb = 1;
                }
            }
            if (flaga && flagb && !no) {
                found = 1;
                for (int i = 0; i < k; ++i) if (p[i] == '$') {
                    int op = get_from(unused, 0);
                    unused ^= 1 << op;
                    p[i] = op + 'a';
                }
                cout << "YES\n" << p << '\n';
                break;
            }
        }
        if (!found) cout << "NO" << '\n';
    }
    return 0;
}