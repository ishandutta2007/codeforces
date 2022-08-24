#include <bits/stdc++.h>
using namespace std;
int n, k;
vector < int > solve(int n, int k, int c) {
    //cout << n << " " << k << " " << c << '\n';
    vector < int > z;
    if (k < 0) return z;
    if (k == 0) {
        for (int i = 1; i <= n; i++) z.push_back(i + c);
        return z;
    }
    if (n == 1 && k > 0) {
        return z;
    }
    if (n == 1) {
        z.push_back(1 + c);
        return z;
    }
    int a = n / 2;
    int b = (n + 1) / 2;
    int m = k / 2;
    int t = (k + 1) / 2;
    if (m % 2 != 0) {
        vector < int > x = solve(a, m - 1, c + b);
        vector < int > y = solve(b, t - 1, c);
        if (x.size() == 0 || y.size() == 0) {
            return z;
        }
        for (int i = 0; i < x.size(); i++) z.push_back(x[i]);
        for (int i = 0; i < y.size(); i++) z.push_back(y[i]);
        return z;
    }
    else {
        vector < int > x = solve(a, m - 2, c + b);
        vector < int > y = solve(b, t, c);
        if (x.size() == 0 || y.size() == 0) {
            return z;
        }
        for (int i = 0; i < x.size(); i++) z.push_back(x[i]);
        for (int i = 0; i < y.size(); i++) z.push_back(y[i]);
        return z;
    }
}
int main(){
    cin >> n >> k;
    vector < int > a = solve(n, k - 1, 0);
    if (k % 2 == 0) {
        cout << -1;
        return 0;
    }
    if (a.size() == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
return 0;
}