#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;

int n, a, b, moda[MAXN], modb[MAXN];
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s; n = strlen(s);
    cin >> a >> b;

    moda[0] = 0;
    for (int i=0; i<n; i++)
        moda[i+1] = (moda[i]*10%a+s[i]-'0')%a;

    int pw10 = 1;
    modb[n] = 0;
    for (int i=n-1; i>=0; i--) {
        modb[i] = (modb[i+1]+(s[i]-'0')*pw10%b)%b;
        pw10 = (pw10*10)%b;
    }

    for (int i=1; i<n; i++) {
        if (s[i] != '0' && moda[i] == 0 && modb[i] == 0) {
            cout << "YES\n";
            for (int j=0; j<n; j++) {
                if (j == i) cout << '\n';
                cout << s[j];
            }
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}