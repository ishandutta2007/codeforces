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

const int N = 205;

struct mat { ll a[N][N]; } ans, x;

mat operator * (const mat a, const mat b) {
    mat ans; memset(ans.a, -0x3f, sizeof(ans.a));
    for(register int i = 0; i <= 200; i++) {
        for(register int j = 0; j <= 200; j++) {
            for(register int k = 0; k <= 200; k++) {
                ans.a[i][j] = max(ans.a[i][j], a.a[i][k] + b.a[k][j]);
                // cout << ans.a[i][j] << " " << a.a[i][k] << " " << b.a[k][j] << endl;
            }
        }
    }
    return ans;
}

queue <int> q;
char c[N];
int a[N], ch[N][26], fail[N], val[N];
int n, len, tot;
ll l, maxn;

int main() {
    read(n); read(l);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1); len = strlen(c + 1);
        int now = 0;
        for(register int j = 1; j <= len; j++) {
            int x = c[j] - 'a';
            if(!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
        val[now] += a[i];
    }
    for(register int i = 0; i <= 25; i++) if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        val[u] += val[fail[u]];
        for(register int i = 0; i <= 25; i++) {
            if(!ch[u][i]) { ch[u][i] = ch[fail[u]][i]; continue; }
            int v = ch[u][i], tmp = fail[u];
            while(tmp && !ch[tmp][i]) tmp = fail[tmp];
            fail[v] = ch[tmp][i];
            q.push(v);
        }
    }
    memset(x.a, -0x3f, sizeof(x.a));
    for(register int i = 0; i <= tot; i++) {
        for(register int j = 0; j <= 25; j++) {
            // fprintf(stderr, "i = %d, j = %d, val = %d\n", i, ch[i][j], val[ch[i][j]]);
            x.a[i][ch[i][j]] = val[ch[i][j]];
        }
    }
    ans = x; --l;
    while(l) {
        if(l & 1) ans = ans * x;
        l >>= 1; x = x * x;
    }
    for(register int i = 0; i <= tot; i++) maxn = max(maxn, ans.a[0][i]);
    print(maxn, '\n');
    return 0;
}