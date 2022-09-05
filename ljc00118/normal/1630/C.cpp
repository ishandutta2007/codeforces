#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

multiset <int> dp;
vector <int> vec[N];
int a[N], l[N], r[N];
int n, ans, maxn;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
    }
    dp.insert(0); vec[1].push_back(0);
    for (int i = 0; i < n; i++) {
        for (auto j : vec[i]) dp.erase(dp.find(j));
        int nowdp = *dp.begin();
        dp.insert(nowdp + 1);
        vec[i + 2].push_back(nowdp + 1);
        dp.insert(nowdp + 2);
        vec[r[a[i + 1]] + 1].push_back(nowdp + 2);
        if (i != 0 && r[a[i]] != i) {
            dp.insert(nowdp + 1);
            vec[r[a[i]] + 1].push_back(nowdp + 1);
        }
    }
    for (auto i : vec[n]) dp.erase(dp.find(i));
    print(n - *dp.begin(), '\n');
    return 0;
}