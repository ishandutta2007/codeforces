#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set < char > x1, x2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    for (int i = 0; i < 5; i++) {
        string a;
        cin >> a;
        x1.insert(a[0]);
        x2.insert(a[1]);
    }
    if (x1.count(s[0])) {
        cout << "YES";
    }
    else if (x2.count(s[1])) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}