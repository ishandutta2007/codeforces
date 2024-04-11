#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

vector <pii> v[2];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[(i + j) % 2].emplace_back(i, j);
        }
    }
    while (v[0].size() && v[1].size()) {
        int x; cin >> x;
        if (x == 1) {
            pii tem = v[1][(int)v[1].size() - 1];
            cout << 2 << " " << tem.first << " " << tem.second << endl;
            v[1].pop_back();
        } else {
            pii tem = v[0][(int)v[0].size() - 1];
            cout << 1 << " " << tem.first << " " << tem.second << endl;
            v[0].pop_back();
        }
    }
    while (v[0].size() || v[1].size()) {
        int x; cin >> x;
        pii tem;
        if (v[0].size()) {
            if (x == 1) x = 3;
            else x = 1;
            tem = v[0][(int)v[0].size() - 1];
            v[0].pop_back();
        } else {
            if (x == 2) x = 3;
            else x = 2;
            tem = v[1][(int)v[1].size() - 1];
            v[1].pop_back();
        }
        cout << x << " " << tem.first << " " << tem.second << endl;
    }
    return 0;
}