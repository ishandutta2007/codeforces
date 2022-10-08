
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, k;
vector<pair<int, string>> v;

void makefork(int k) {
    if(k <= n - 1) {
        v.emplace_back(k, "U");
    }else {
        v.emplace_back(n - 1, "U");
        k -= (n - 1);
        if(k <= 3 * (n - 1)) {
            v.emplace_back(k / 3, "LRD");
            k %= 3;
            if(k == 1) {
                v.emplace_back(1, "L");
            }else if(k == 2) {
                v.emplace_back(1, "LR");
            }
        }else {
            v.emplace_back(n - 1, "LRD");
            k -= (n - 1);
            if(k > 0) {
                v.emplace_back(1, "L");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    if(k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n == 1) {
        if(k <= m - 1) {
            v.emplace_back(k, "R");
        }else {
            v.emplace_back(m - 1, "R");
            v.emplace_back(k - (m - 1), "L");
        }
    }else if(m == 1) {
        if(k <= n - 1) {
            v.emplace_back(k, "D");
        }else {
            v.emplace_back(n - 1, "D");
            v.emplace_back(k - (n - 1), "U");
        }
    }else {
        if(k <= n - 1) {
            v.emplace_back(k, "D");
        }else {
            k -= (n - 1);
            v.emplace_back(n - 1, "D");
            if(k <= (m - 1)) {
                v.emplace_back(k, "R");
            }else {
                k -= (m - 1);
                v.emplace_back(m - 1, "R");
                while(k > 0) {
                    makefork(k);
                    k -= 4 * (n - 1) + 1;
                }
            }
        }
    }
    int cnt = 0;
    for(auto p : v) cnt += (p.first > 0);
    cout << cnt << endl;
    for(auto p : v) {
        if(p.first > 0) {
            cout << p.first << " " << p.second << endl;
        }
    }
}