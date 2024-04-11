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
 
const int N = (1 << 21) + 5;
 
vector <int> ans;
int a[N], v[N];
int T, n, m, now;
ll sum;
 
int main() {
    read(T);
    while (T--) {
        read(n); read(m); sum = 0; now = 1; ans.clear();
        for (int i = 1; i < (1 << n); i++) read(a[i]), v[i] = a[i], sum += a[i];
        while (now < (1 << m)) {
            int id = now;
            while (1) {
                if (!v[id << 1] && !v[id << 1 | 1]) break;
                if (v[id << 1] > v[id << 1 | 1]) id = id << 1;
                else id = id << 1 | 1;
            }
            if (id >= (1 << m)) {
                ans.push_back(now);
                // fprintf(stderr, "i = %d, id = %d\n", i, id);
                id = now; sum -= v[now];
                while (id) {
                    if (!v[id << 1] && !v[id << 1 | 1]) break;
                    if (v[id << 1] > v[id << 1 | 1]) {
                        v[id] = v[id << 1];
                        id = id << 1;
                    } else {
                        v[id] = v[id << 1 | 1];
                        id = id << 1 | 1;
                    }
                }
                v[id] = 0;
                // fprintf(stderr, "id = %d\n", id);
            } else ++now;
        }
        // for (int i = 1; i < (1 << m); i++) used[v[i]] = 1;
        print(sum, '\n');
        for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
        // for (int i = (1 << n) - 1; i >= 1; i--) if (!used[a[i]]) print(i, ' ');
        putchar('\n');
    	for (int i = 0; i < (1 << m); i++) v[i] = 0;
    }
    return 0;
}