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

vector < vector <int> > now, tmp;
vector <int> zero, one;
int ans[N][N];
int n;

int main() {
    memset(ans, -1, sizeof(ans));
    read(n);
    now.push_back(vector <int> (n + 1, 0));
    for(register int i = 1; i <= n + 1; i++) now[0][i - 1] = i;
    for(register int i = 1; i <= n; i++) {
        int a; read(a);
        int can = min(a, n + 1 - a);
        tmp.clear();
        for(register int j = 0; j < (int)now.size(); j++) {
            if(now[j].size() >= 2 && can) {
                ans[now[j][0]][i] = 0;
                ans[now[j][1]][i] = 1;
                --a; --can;
            }
        }
        for(register int j = 0; j < (int)now.size(); j++) {
            zero.clear(); one.clear();
            for(register int k = 0; k < (int)now[j].size(); k++) {
                if(ans[now[j][k]][i] == -1) {
                    if(a) ans[now[j][k]][i] = 1, --a;
                    else ans[now[j][k]][i] = 0;
                }
                if(ans[now[j][k]][i] == 1) one.push_back(now[j][k]);
                else zero.push_back(now[j][k]);
            }
            if(zero.size()) tmp.push_back(zero);
            if(one.size()) tmp.push_back(one);
        }
        now = tmp;
    }
    print(n + 1, '\n');
    for(register int i = 1; i <= n + 1; i++) {
        for(register int j = 1; j <= n; j++) {
            putchar(ans[i][j] + '0');
        }
        putchar('\n');
    }
    return 0;
}