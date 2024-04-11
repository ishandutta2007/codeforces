#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000100;

int n, p[MAXN];
char s[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = strlen(s);
    p[0] = -1;
    for (int i=0; i<n; i++) {
        int k = p[i];
        while (k >= 0 && s[k] != s[i]) k = p[k];
        p[i+1] = k+1;
    }

    //for (int i=0; i<=n; i++) cout << p[i] << endl;

    int a = 0;
    for (int i=1; i<n; i++) a = max(a, p[i]);
    int k = p[n];
    while (k>0) {
        if (a >= k) {
            s[k] = 0;
            cout << s;
            return 0;
        }
        k = p[k];
    }
    cout << "Just a legend";
}