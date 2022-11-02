#include <bits/stdc++.h>
using namespace std;

int f1[30], f2[30], f3[30];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string a, b, c;
    cin >> a >> b >> c;
    for (int i=0; i<a.length(); i++) f1[a[i]-'a']++;
    for (int i=0; i<b.length(); i++) f2[b[i]-'a']++;
    for (int i=0; i<c.length(); i++) f3[c[i]-'a']++;

    int b1 = 0, b2 = 0;
    for (int i=0; i<=a.length(); i++) {
        bool b = 1;
        for (int j=0; j<26; j++)
            if (f2[j]*i > f1[j]) b = 0;
        if (!b) break;

        int mi = 1e9;
        for (int j=0; j<26; j++)
            if (f3[j])
                mi = min(mi, (f1[j]-f2[j]*i)/f3[j]);
        if (i+mi > b1+b2) b1 = i, b2 = mi;
    }

    for (int i=0; i<b1; i++) {
        cout << b;
        for (int j=0; j<26; j++) f1[j] -= f2[j];
    }
    for (int i=0; i<b2; i++) {
        cout << c;
        for (int j=0; j<26; j++) f1[j] -= f3[j];
    }

    for (int i=0; i<26; i++)
        for (int j=0; j<f1[i]; j++) cout << char(i+'a');
}