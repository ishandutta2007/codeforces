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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

char c[105];
int cnt[27];
int T, n, minn, maxn, tot;

int main() {
    read(T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", c + 1);
        n = strlen(c + 1);
        for(register int i = 1; i <= n; i++) ++cnt[c[i] - 'a'];
        for(register int i = 0; i <= 25; i++) if(cnt[i]) { minn = i; break; }
        for(register int i = 25; i >= 0; i--) if(cnt[i]) { maxn = i; break; }
        if(maxn - minn == 1 || (maxn - minn == 2 && cnt[minn + 1])) {
            printf("No answer\n");
        } else {
            int last = -1;
            for(register int i = minn + 1; i <= maxn; i++) {
                if(cnt[i]) {
                    if(last == -1 || (last != -1 && last != i - 1)) {
                        while(cnt[i] > 0) { putchar(i + 'a'); --cnt[i]; }
                        last = i;
                    }
                }
            }
            for(register int i = minn; i <= maxn; i++) {
                while(cnt[i] > 0) { putchar(i + 'a'); --cnt[i]; }
            }
            putchar('\n');
        }
    }
    return 0;
}