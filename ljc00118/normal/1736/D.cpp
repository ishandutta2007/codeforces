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

char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n); n *= 2; scanf("%s", c + 1);
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++) ++cnt[c[i] - '0']; 
        if (cnt[0] % 2 == 1 || cnt[1] % 2 == 1) {
            print(-1, '\n');
            continue;
        }
        vector <int> vec;
        for (int i = 1, cur = 0; i <= n; i += 2) {
            if (c[i] != c[i + 1]) {
                if (c[i] - '0' == cur) {
                    vec.push_back(i);
                    cur ^= 1;
                } else {
                    vec.push_back(i + 1);
                    cur ^= 1;
                }
            }
        }
        print(vec.size(), ' ');
        for (auto i : vec) print(i, ' ');
        putchar('\n');
        for (int i = 1; i <= n; i += 2) print(i, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}