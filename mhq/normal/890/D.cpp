#include <bits/stdc++.h>
using namespace std;
int n;
int st[26];
int fn[26];
string s;
vector < string > pool;
vector < int > can;
bool used[26];
bool c[26];
bool used1[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(st, -1, sizeof st);
    memset(fn, -1, sizeof fn);
    for (int i = 0; i  < n; i++) {
        cin >> s;
        if (s.size() == 1) c[s[0] - 'a'] = true;
        for (int j = 0; j < s.size() - 1; j++) {
            c[s[j] - 'a'] = true;
            c[s[j + 1] - 'a'] = true;
            if (st[s[j] - 'a'] == -1) {
                st[s[j] - 'a'] = s[j + 1] - 'a';
            }
            if (fn[s[j + 1] - 'a'] == -1) {
                fn[s[j + 1] - 'a'] = s[j] - 'a';
            }
            if (st[s[j] - 'a'] != s[j + 1] - 'a') {
                cout << "NO";
                return 0;
            }
            if (fn[s[j + 1] - 'a'] != s[j] - 'a') {
                cout << "NO";
                return 0;
            }
        }
    }
    //for (int i = 0; i < 26; i++) cout << st[i] << '\n';
    for (int i = 0; i < 26; i++) {
        int t = i;
        while (t != -1) {
            if (used1[t]) {
                cout << "NO";
                return 0;
            }
            used1[t] = true;
            t = st[t];
        }
        for (int j = 0; j < 26; j++) used1[j] = false;
    }
    for (int i = 0; i < 26; i++) {
        int t = i;
        if (fn[t] == -1 && st[t] != -1) {
                //cout << t << "  " << i << '\n';
            string s;
            while (t != -1) {
                //cout << t;
                if (used[t]) {
                    cout << "NO";
                    return 0;
                }
                used[t] = true;
                s += t + 'a';
                t = st[t];
            }
            pool.push_back(s);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (c[i] == true && used[i] == false)  {
            char c = 'a' + i;
            string s;
            s += c;
            pool.push_back(s);
        }
    }
    sort(pool.begin(), pool.end());
    string ans;
    for (int i = 0; i < pool.size(); i++) {
        ans += pool[i];
    }
    cout << ans;
}