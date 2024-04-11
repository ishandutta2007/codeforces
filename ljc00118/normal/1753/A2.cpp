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

int a[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        vector <int> vec;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (a[i] != 0) vec.push_back(i);
        }
        if ((int)vec.size() % 2 != 0) {
            print(-1, '\n');
            continue;
        }
        vector <pii> ans;
        int las = 0;
        for (int i = 0; i < (int)vec.size(); i += 2) {
            if (vec[i] != las + 1) {
                ans.emplace_back(las + 1, vec[i] - 1);
            }
            int x = a[vec[i]], y = a[vec[i + 1]];
            if ((vec[i + 1] - vec[i]) % 2 == 0) y = -y;
            if (x == y) {
                ans.emplace_back(vec[i], vec[i + 1]);
            } else {
                ans.emplace_back(vec[i], vec[i]);
                ans.emplace_back(vec[i] + 1, vec[i + 1]);
            }
            las = vec[i + 1];
        }
        if (las != n) ans.emplace_back(las + 1, n);
        print((int)ans.size(), '\n');
        for (auto i : ans) printf("%d %d\n", i.first, i.second);
    }
    return 0;
}