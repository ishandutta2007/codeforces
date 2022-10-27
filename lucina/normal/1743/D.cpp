#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;
string s;
int as[nax];
int mx[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> s;
    int fnt = 0;
    while (!s.empty() && s[fnt] == '0') fnt += 1;
    s.erase(s.begin(), s.begin() + fnt);
    if (s.empty()) {
        cout << "0\n";
    }
    n = s.size();
    int best_improve = n;
    for (int i = 0 ; i < n ; ++ i) {
        as[i] = s[i] - '0';
        mx[i] = as[i];
    }

    for (int i = 1 ; i < min(n, 40) ; ++ i) {
        bool ok = true;
        for (int w = 0 ; w < i ; ++ w) {
            if (mx[w] > as[w]) ok = false;
        }
        if (!ok) continue;
        for (int j = 0 ; j < i ; ++ j) {
            bool improve = false;
            for (int k = j ; k < n ; ++ k) {
                int b = mx[i + (k - j)] - (as[k] | as[i + (k - j)]);
                if (b > 0) break;
                if (b < 0) {
                    improve = true;
                    break;
                }
            }
            if (improve) {
                for (int k = j ; k < n ; ++ k) {
                    mx[i + (k - j)] = (as[k] | as[i + (k - j)]);
                }
            }
        }
    }
    for (int i = 0 ; i < n ; ++ i)
        cout << mx[i];
    cout << '\n';
    /**
        00100010101010
        The upper string must be

    */




}