#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y;
bool yes;

void Check(ll x)
{
    string X, Y;
    ll num = y;
    while (x) {
        if (x % 2) X += "1";
        else X += "0";
        x /= 2; 
    }
    while (num) {
        if (num % 2) Y += "1";
        else Y += "0";
        num /= 2;
    }
    string rX = X; reverse(rX.begin(), rX.end());
    for (int i = 0; i < Y.size(); i++) if (i == 0 || Y.substr(0, i) == string(i, '1'))
        for (int j = i; j < Y.size(); j++) if (j + 1 == Y.size() || Y.substr(j + 1) == string(int(Y.size()) - 1 - j, '1'))
            if (Y.substr(i, j - i + 1) == X || Y.substr(i, j - i + 1) == rX) {
                yes = true;
                return;
            }
}

int main()
{
    cin >> x >> y;
    if (x == y) { printf("YES\n"); return 0; }
    if (x % 2 == 0) {
        Check(x * 2ll + 1ll);
        while (x % 2 == 0) x /= 2;
    }
    Check(x);
    printf("%s\n", yes? "YES": "NO");
    return 0;
}