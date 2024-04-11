#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;
string l, r;

string add1(string x) {
    int m = x.size() - 1;
    while (x[m] == '1') -- m;
    x[m] = '1';
    for (int j = m + 1 ; j < x.size() ; ++ j)
        x[j] = '0';
    return x;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    cin >> l >> r;

    string res;

        if (n == 2) {
        if (r[0] != '1') {
            cout << r[1] << '\n';
        } else if (l == r) {
            cout << r << '\n';
        } else cout << "11";
        return 0;
    }


    for (int i = 0 ; i < n - 2 ; ++ i) {
        if (r[i] != l[i]) {
            for (int j = 0 ; j < i ; ++ j)
                res += '0';
            for (int j = i ; j < n ; ++ j) res += '1';
            break;
        }
    }

    if (!res.empty() && res < r) {
        res = r;
        int x = (l[n - 2] - '0') * 2 + (l[n - 1] - '0');
        int y = (r[n - 2] - '0') * 2 + (r[n - 1] - '0');
        if (y >= 2) {
            res[n - 2] = res[n - 1] = '1';
        } else {
            string cl = l, cr = r;
            l.pop_back(); l.pop_back();
            r.pop_back(); r.pop_back();
            if (add1(l) != r || x <= 1) {
                res.back() = '1';
                res[n - 2] = '0';
            }
            l = cl, r = cr;
        }
    }

    if (res.empty()) {
        int x = (l[n - 2] - '0') * 2 + (l[n - 1] - '0');
        int y = (r[n - 2] - '0') * 2 + (r[n - 1] - '0');
        if (x - y > 2) {
            res = r;
            res[n - 2] = '1';
            res[n - 1] = '1';
        } else res = r;
    }
    res = max(res, r);


    reverse(res.begin(), res.end());
    while (!res.empty() && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    cout << (res.empty() ? "0" : res)  << '\n';

}