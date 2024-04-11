#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 400100;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int X1 = 29;
const int X2 = 31;

int n, d;
char s[maxn], t[maxn];
ll pw1[maxn], pw2[maxn];
ll p1[maxn], p2[maxn];
ll q1[maxn], q2[maxn];

bool palin(int l, int r) {
    if (l < 0) return 0;
    return 
    ll(p1[r + 1] - p1[l] + mod1) % mod1 * pw1[n - l] % mod1 == ll(q1[r + 1] - q1[l] + mod1) % mod1 * pw1[r] % mod1 && 
    ll(p2[r + 1] - p2[l] + mod2) % mod2 * pw2[n - l] % mod2 == ll(q2[r + 1] - q2[l] + mod2) % mod2 * pw2[r] % mod2;
}

void add(int i, char c) {
    t[i] = c;
    c -= 'a';
    p1[i + 1] = (p1[i] + ll(pw1[i]) * c % mod1) % mod1;
    p2[i + 1] = (p2[i] + ll(pw2[i]) * c % mod2) % mod2;
    q1[i + 1] = (q1[i] + ll(pw1[n-i]) * c % mod1) % mod1;
    q2[i + 1] = (q2[i] + ll(pw2[n-i]) * c % mod2) % mod2;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> d >> s;
    n = strlen(s);

    bool flag = 0;
    //GREATER not GREATER EQUAL :O
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'z') s[i] = 'a';
        else {
            s[i]++;
            flag = 1;
            break;
        }
    }

    if (!flag) {
        cout << "Impossible\n";
        return 0;
    }

    flag = 0;

    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * X1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * X2 % mod2;
    }

    for (int i = 0; i < n; i++) {
        if (!flag) {
            add(i, s[i]);
            if (palin(i - d + 1, i) || palin(i - d, i)) {
                while (i >= 0) {
                    for (char c = s[i] + 1; c <= 'z'; c++) {
                        add(i, c);
                        if (!palin(i - d + 1, i) && !palin(i - d, i)) {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag) break;

                    i--;
                }

                if (!flag) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
        } else {
            bool good = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                add(i, c);
                if (!palin(i - d + 1, i) && !palin(i - d, i)) {
                    good = 1;
                    break;
                }
            }
            
            if (!good) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    cout << t << '\n';
}