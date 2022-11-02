#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

char s[MAXN], t[MAXN];
int freq[200];

int conv(char c) {
    if (c >= 'a' && c <= 'z') return c-'a';
    else return c-'A'+26;
}

int main() {
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    for (int i=0; i<m; i++) freq[conv(t[i])]++;
    int a=0, b=0;
    for (int i=0; i<n; i++)
        if (freq[conv(s[i])])
            a++, freq[conv(s[i])]--, s[i] = 0;
    for (int i=0; i<n; i++)
        if (s[i] && freq[(conv(s[i])+26)%52])
            b++, freq[(conv(s[i])+26)%52]--;
    cout << a << ' ' << b;
}