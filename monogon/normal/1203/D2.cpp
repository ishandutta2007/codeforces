
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
string s, t;
// posl[i] = minimum length prefix of s containing t[0, ..., i).
// posr[i] = minimum length suffix of t containing t[i, ...]
int posl[MAX_N], posr[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int i = 0; // index of s
    int j = 0; // index of t
    posl[0] = 0;
    while(i < n && j < m) {
        if(s[i] == t[j]) {
            j++;
            posl[j] = i + 1;
        }
        i++;
    }
    posr[m] = 0;
    i = n - 1;
    j = m - 1;
    while(i >= 0 && j >= 0) {
        if(s[i] == t[j]) {
            posr[j] = n - i;
            j--;
        }
        i--;
    }
    int M = INT_MAX;
    for(int i = 0; i <= m; i++) {
        M = min(M, posl[i] + posr[i]);
    }
    cout << (n - M) << endl;
}