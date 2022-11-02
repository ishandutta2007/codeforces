#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

string s, t;
int freq[200];

bool good(int x) {
    string a = "", b = t.substr(x);
    for (int i='z'; i>='a'; i--)
        for (int j=0; j<freq[i]; j++)
            a += i;
    return a > b;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s >> t;
    for (int i=0; i<s.length(); i++) freq[s[i]]++;
    if (!good(0)) {
        cout << "-1\n";
        return 0;
    }
    for (int i=0; i<=s.length(); i++) {
        if (i<s.length() && freq[t[i]]) {
            freq[t[i]]--;
            if (good(i+1)) continue;
            freq[t[i]]++;
        }
        for (int j=0; j<i; j++) cout << t[j];
        for (int j='a'; j<='z'; j++)
            if (freq[j] && j > t[i]) {
                freq[j]--;
                cout << char(j);
                break;
            }
        for (int j='a'; j<='z'; j++)
            for (int k=0; k<freq[j]; k++)
                cout << char(j);
        return 0;
    }
}