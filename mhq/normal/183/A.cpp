#include <bits/stdc++.h>
using namespace std;
int n;
long long a, b, c, d, e;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "UR") a++;
        if (s == "UL") b++;
        if (s == "DL") c++;
        if (s == "DR") d++;
        if (s == "ULDR") e++;
    }
    cout << ((a + c) + e + 1) * ((b + d) + e + 1);
    return 0;
}