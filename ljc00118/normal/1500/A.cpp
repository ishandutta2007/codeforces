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

const int N = 2e5 + 5, M = 5e6 + 5;

vector <pii> res[M];
int a[N], pre[M];
int n, las, id1, id2, id3, id4;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    int id1 = 0, id2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!pre[a[i]]) pre[a[i]] = i;
        else {
            if (!id1) id1 = pre[a[i]], id3 = i, pre[a[i]] = 0;
            else {
                id2 = pre[a[i]], id4 = i;
                break;
            }
        }
    }
    if (id4) {
        printf("YES\n%d %d %d %d\n", id1, id2, id3, id4);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = a[i] + a[j];
            for (int k = 0; k < (int)res[sum].size(); k++) {
                if (res[sum][k].first != i && res[sum][k].first != j && res[sum][k].second != i && res[sum][k].second != j) {
                    printf("YES\n%d %d %d %d\n", i, j, res[sum][k].first, res[sum][k].second);
                    exit(0);
                }
            }
            res[sum].emplace_back(i, j);
        }
    }
    printf("NO\n");
    return 0;
}