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
 
const int N = 1e5 + 5;
 
vector <pii> ans;
vector <int> p[4];
int a[N];
int n, tot;
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), p[a[i]].push_back(i);
    int cando0 = 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] != 0) cando0 = 0;
    }
    if (cando0) {
        print(0, '\n');
        return 0;
    }
    if (p[2].size() > p[1].size()) {
        puts("-1");
        return 0;
    }
    for (int i = (int)p[2].size() - 1, j = (int)p[1].size() - 1; i >= 0; i--, j--) {
        if (p[2][i] > p[1][j]) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < (int)p[1].size(); i++) {
        ++tot;
        ans.push_back(make_pair(n - i, p[1][i]));
    }
    int pos = 0;
    for (int i = 0; i < (int)p[2].size(); i++) {
        while (p[2][i] > p[1][pos]) ++pos;
        ans.push_back(make_pair(n - pos, p[2][i])); ++pos;
    }
    if (p[3].size()) {
        if (!p[1].size()) {
            puts("-1");
            return 0;
        }
        int x, y;
        if (pos == tot) {
            x = n - tot + 1; y = p[2][p[2].size() - 1];
        } else {
            x = n - tot + 1; y = p[1][p[1].size() - 1];
        }
        if (p[3][p[3].size() - 1] > y) {
            puts("-1");
            return 0;
        }
        for (int i = (int)p[3].size() - 1; i >= 0; i--) {
            ans.push_back(make_pair(x - 1, y));
            ans.push_back(make_pair(x - 1, p[3][i]));
            --x; y = p[3][i];
        }
    }
    print((int)ans.size(), '\n');
    for (int i = 0; i < (int)ans.size(); i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
    return 0;
}