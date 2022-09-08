#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2005;

vector <pii> ans;
char c[N], go[N];
int T, n, k;

int main() {
    read(T);
    while(T--) {
        read(n); read(k); ans.clear(); --k;
        scanf("%s", c + 1);
        for(register int i = 1; i <= k; i++) {
            go[i * 2 - 1] = '(';
            go[i * 2] = ')';
        }
        for(register int i = 1; i <= n / 2 - k; i++) {
            go[k * 2 + i] = '(';
            go[k * 2 + i + n / 2 - k] = ')';
        }
        for(register int i = 1; i <= n; i++) {
            if(c[i] != go[i]) {
                for(register int j = i + 1; j <= n; j++) {
                    if(c[j] == go[i]) {
                        reverse(c + i, c + j + 1);
                        ans.push_back(make_pair(i, j));
                        break;
                    }
                }
            }
        }
        print((int)ans.size(), '\n');
        for(register int i = 0; i < (int)ans.size(); i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
    }
    return 0;
}