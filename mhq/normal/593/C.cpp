#include <bits/stdc++.h>
using namespace std;
string p;
string q;
int n;
int x[55];
int y[55];
int r[55];
string to(int a) {
    string s;
    if (a == 0) {
        s += "0";
        return s;
    }
    while (a > 0) {
        s += char(a % 10) + '0';
        a /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
string ab(string x) {
    string s = "abs(" + x + ")";
    return s;
}
string sum(string p, string q) {
    string s = "(" + p + "+" + q + ")";
    return s;
}
string dif(string p, string q) {
    string s = "(" + p + "-" + q + ")";
    return s;
}
string mult(string p, string q) {
    string s = "(" + p + "*" + q + ")";
    return s;
}
string t() {
    return "t";
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //cout << t();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    string p;
    p = mult(to((x[1] + 1) / 2),  dif( sum ( ab( dif(to(50), ab(dif(t(), to(1))))) , ab(dif( ab(dif( t(), to(1))),  to(1))) ), to(49) ) );
    for (int i = 2; i <= n; i++) {
        string q = mult(to((x[i] + 1) / 2),  dif( sum ( ab( dif(to(50), ab(dif(t(), to(i))))) , ab(dif( ab(dif( t(), to(i))),  to(1))) ), to(49) ) );
        p = sum(p, q);
    }
    cout << p << '\n';
    for (int i = 1; i <= n; i++) x[i] = y[i];
     p = mult(to((x[1] + 1) / 2),  dif( sum ( ab( dif(to(50), ab(dif(t(), to(1))))) , ab(dif( ab(dif( t(), to(1))),  to(1))) ), to(49) ) );
    for (int i = 2; i <= n; i++) {
        string q = mult(to((x[i] + 1) / 2),  dif( sum ( ab( dif(to(50), ab(dif(t(), to(i))))) , ab(dif( ab(dif( t(), to(i))),  to(1))) ), to(49) ) );
        p = sum(p, q);
    }
    cout << p << '\n';
    /*for (int i = 2; i <= n; i++) {
        p = "(p+"
    }*/

    return 0;
}