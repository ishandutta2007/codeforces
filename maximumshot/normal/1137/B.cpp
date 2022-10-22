#include <bits/stdc++.h>

using namespace std;

vector<int> pref(string s) {
    int n = (int)s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

void fin(int cnt[2]) {
    for (int x = 0;x < 2; x++) {
        for (int i = 0; i < cnt[x]; i++) {
            cout << char(x + '0');
        }
    }
    cout << "\n";
    exit(0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;

    cin >> s >> t;

    if (!count(t.begin(), t.end(), '0') || !count(t.begin(), t.end(), '1')) {
        sort(s.begin(), s.end());
        cout << s << "\n";
        return 0;
    }

    int pr = pref(t).back();

    int cnt[2];

    cnt[0] = count(s.begin(), s.end(), '0');
    cnt[1] = count(s.begin(), s.end(), '1');

    for (char c : t) {
        if (!cnt[c - '0']) {
            fin(cnt);
        }
        cnt[c - '0']--;
        cout << c;
    }

    for (;;) {
        for (int i = pr; i < (int)t.size(); i++) {
            char c = t[i];
            if (!cnt[c - '0']) {
                fin(cnt);
            }
            cnt[c - '0']--;
            cout << c;
        }
    }

    cout << "\n";

    return 0;
}