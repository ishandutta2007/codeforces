#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 13, P2 = 1e9 + 9, M = 1e9 + 7;

int wordHash(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret = ((long long)ret * P + s[i]) % M;
    }
    return ret;
}

int calculateHash(string s) {
    if (s.size() % 2 == 1) {
        return wordHash(s);
    }
    if (s.size() == 0) {
        return 0;
    }
    string s1 = "";
    for (int i = 0; i < s.size() / 2; i++) {
        s1 += s[i];
    }
    int h1 = calculateHash(s1);
    s1 = "";
    for (int i = s.size() / 2; i < s.size(); i++) {
        s1 += s[i];
    }
    int h2 = calculateHash(s1);
    if (h1 > h2) {
        swap(h1, h2);
    }
    return (((531513*h1*h2 + 425135) * h1 + 31511) * h2 + 315813) % M;
}

bool equivalent(string a, string b) {
    return calculateHash(a) == calculateHash(b);
}

int main() {

    ios_base::sync_with_stdio(0);

    string a, b;

    cin >> a >> b;

    cout << (equivalent(a, b) ? "YES\n" : "NO\n");

    return 0;
}