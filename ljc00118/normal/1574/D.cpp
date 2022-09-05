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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

priority_queue < pair <int, vector <int> > > Q;
vector <int> b[N];
int c[N], a[15][N], used[N];
int n, m, ans; vector <int> qwq;

bool operator < (vector <int> a, vector <int> b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return 0;
}

bool operator == (vector <int> a, vector <int> b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void add(vector <int> tem) {
    int pos = lower_bound(b + 1, b + m + 1, tem) - b;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i + 1][tem[i]];
    if (pos <= m && tem == b[pos]) {
        if (!used[pos]) {
            Q.push(make_pair(sum, tem));
            used[pos] = 1;
            return;
        } else return;
    }
    if (sum >= ans) {
        ans = sum;
        qwq = tem;
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(c[i]);
        for (int j = 1; j <= c[i]; j++) read(a[i][j]);
    }
    read(m);
    for (int i = 1; i <= m; i++) {
        b[i].resize(n);
        for (int j = 0; j < n; j++) read(b[i][j]);
    }
    sort(b + 1, b + m + 1);
    vector <int> tem;
    for (int i = 1; i <= n; i++) tem.push_back(c[i]);
    add(tem);
    while (!Q.empty()) {
        pair <int, vector <int> > t = Q.top(); Q.pop();
        if (t.first <= ans) break;
        for (int i = 0; i < n; i++) {
            if (t.second[i] > 1) {
                --t.second[i];
                add(t.second);
                ++t.second[i];
            }
        }
    }
    for (int i = 0; i < n; i++) print(qwq[i], i == n - 1 ? '\n' : ' ');
    return 0;
}