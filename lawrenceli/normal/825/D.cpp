#include <bits/stdc++.h>

using namespace std;

string s, t;
int fs[30], ft[30];
long long fn[30];

int conv(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    return 26;
}

void makefn(int m) {
    for (int i = 0; i < 30; i++) fn[i] = (long long)(ft[i]) * m;
}

bool check(int m) {
    makefn(m);
    long long need = 0;
    for (int i = 0; i < 26; i++) need += max(0LL, fn[i] - fs[i]);
    return need <= fs[26];
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) fs[conv(s[i])]++;
    for (int i = 0; i < t.length(); i++) ft[conv(t[i])]++;

    int lo = 0, hi = 1000000;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    makefn(lo);
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '?') {
            for (int j = 0; j < 26; j++)
                if (fs[j] < fn[j]) {
                    s[i] = char(j + 'a');
                    fs[j]++;
                    break;
                }
            if (s[i] == '?') s[i] = 'a';
        }
    cout << s << '\n';
}