#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    t = t + s;
    cout << t;
    return 0;
}