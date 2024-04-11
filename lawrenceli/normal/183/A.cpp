#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n, a=1, b=1;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        if (s == "UL" || s == "DR") a++;
        else if (s == "UR" || s == "DL") b++;
        else a++, b++;
    }
    cout << ll(a)*b << '\n';
}