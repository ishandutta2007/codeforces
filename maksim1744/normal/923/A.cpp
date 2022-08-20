#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
    }
    int x2;
    cin >> x2;
    vector< int > res(1000001, true);
    for (int i = 0; i < 2; i++) {
        res[i] = false;
    }
    for (int i = 2; i < 1000; i++) {
        if (res[i]) {
            for (int j = i * i; j < res.size(); j += i) {
                res[j] = false;
            }
        }
    }
    vector< int > pr;
    for (int i = 0; i < res.size(); i++) {
        if (res[i]) {
            pr.push_back(i);
        }
    }
    vector< int > p12;
    int x22 = x2;
    for (int i = 2; i < x22 + 1; i++) {
        if (x2 % i == 0) {
            p12.push_back(i);
            while (x2 % i == 0) {
                x2 /= i;
            }
        }
    }
    x2 = x22;
    int x1mn = x2 - p12.back() + 1;
    int x1mx = x2;
    int l = 1, r = x2;
    while (r - l > 1) {
        int c = (r + l) / 2;
        bool ok = false;
        for (int i = 0; i < pr.size(); i++) {
            if (c <= pr[i]) {
                break;
            }
            int t = (c + pr[i] - 1) / pr[i] * pr[i];
            if (t >= x1mn && t <= x1mx) {
                ok = true;
            }
        }
        if (ok) {
            r = c;
        }
        else {
            l = c;
        }
    }
    cout << r;
    return 0;
}