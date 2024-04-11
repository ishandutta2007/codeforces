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

vector <int> vec[N];
queue <int> q[2];
char c[N];
int n, cnt;

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == '0') ++m;
        else --m;
    }
    if (m <= 0) {
        print(-1, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == '0') {
            if (cnt < m) {
                ++cnt;
                q[0].push(cnt);
                vec[cnt].push_back(i);
            } else if (!q[1].empty()) {
                int x = q[1].front(); q[1].pop();
                vec[x].push_back(i); q[0].push(x);
            } else {
                print(-1, '\n');
                return 0;
            }
        }
        if (c[i] == '1') {
            if (!q[0].empty()) {
                int x = q[0].front(); q[0].pop();
                vec[x].push_back(i); q[1].push(x);
            } else {
                print(-1, '\n');
                return 0;
            }
        }
    }
    print(m, '\n');
    for (int i = 1; i <= m; i++) {
        print(vec[i].size(), ' ');
        for (auto j : vec[i]) print(j, ' ');
        putchar('\n');
    }
    return 0;
}