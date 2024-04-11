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

const int N = 1e5 + 5;

int f[255][255][255], nxt[N][26];
int len[5], wz[N];
char c[N], str[5][N];
int n, q;

char readchar() {
    char c = getchar();
    while(c != '+' && c != '-' && !(c >= 'a' && c <= 'z')) c = getchar();
    return c;
}

void chkmin(int &x, int y) { if(y == -1) { y = N + 1; } x = min(x, y); }

void calc(int x, int y, int z) {
    f[x][y][z] = N + 1;
    if(x && ~f[x - 1][y][z]) chkmin(f[x][y][z], nxt[f[x - 1][y][z]][str[1][x] - 'a']);
    if(y && ~f[x][y - 1][z]) chkmin(f[x][y][z], nxt[f[x][y - 1][z]][str[2][y] - 'a']);
    if(z && ~f[x][y][z - 1]) chkmin(f[x][y][z], nxt[f[x][y][z - 1]][str[3][z] - 'a']);
    if(f[x][y][z] == N + 1) f[x][y][z] = -1;
    if(!x && !y && !z) f[x][y][z] = 0;
    // fprintf(stderr, "f[%d][%d][%d] = %d\n", x, y, z, f[x][y][z]);
}

int main() {
    read(n); read(q); scanf("%s", c + 1);
    for(register int i = 0; i < 26; i++) wz[i] = -1;
    for(register int i = n; i >= 0; i--) {
        for(register int j = 0; j < 26; j++) nxt[i][j] = wz[j];
        if(!i) break;
        wz[c[i] - 'a'] = i;
    }
    f[0][0][0] = 0;
    while(q--) {
        char opt = readchar();
        if(opt == '+') {
            int t; read(t);
            char v = readchar();
            str[t][len[t] + 1] = v;
            if(t == 1) {
                ++len[1];
                for(register int j = 0; j <= len[2]; j++) {
                    for(register int k = 0; k <= len[3]; k++) {
                        calc(len[1], j, k);
                    }
                }
            }
            if(t == 2) {
                ++len[2];
                for(register int i = 0; i <= len[1]; i++) {
                    for(register int k = 0; k <= len[3]; k++) {
                        calc(i, len[2], k);
                    }
                }
            }
            if(t == 3) {
                ++len[3];
                for(register int i = 0; i <= len[1]; i++) {
                    for(register int j = 0; j <= len[2]; j++) {
                        calc(i, j, len[3]);
                    }
                }
            }
        } else {
            int t; read(t);
            if(t == 1) {
                --len[1];
                for(register int j = 0; j <= len[2]; j++) {
                    for(register int k = 0; k <= len[3]; k++) {
                        calc(len[1], j, k);
                    }
                }
            }
            if(t == 2) {
                --len[2];
                for(register int i = 0; i <= len[1]; i++) {
                    for(register int k = 0; k <= len[3]; k++) {
                        calc(i, len[2], k);
                    }
                }
            }
            if(t == 3) {
                --len[3];
                for(register int i = 0; i <= len[1]; i++) {
                    for(register int j = 0; j <= len[2]; j++) {
                        calc(i, j, len[3]);
                    }
                }
            }
        }
        if(f[len[1]][len[2]][len[3]] == -1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}