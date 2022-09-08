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

const int N = 4005;

vector <int> ansa, ansb;
char a[N], b[N];
int ca[3], cb[3];
int T, n, flag;

inline int geta(int x) { return (a[x] - '0') + (a[x + 1] - '0'); }
inline int getb(int x) { return (b[x] - '0') + (b[x + 1] - '0'); }

int main() {
    read(T);
    while(T--) {
        memset(ca, 0, sizeof(ca)); memset(cb, 0, sizeof(cb)); ansa.clear(); ansb.clear();
        scanf("%s%s", a + 1, b + 1); n = strlen(a + 1);
        for(register int i = 1; i <= n; i += 2) ++ca[geta(i)], ++cb[getb(i)];
        flag = 0;
        for(register int i = 0; i <= 2; i++) {
            if(ca[i] != cb[i]) {
                flag = 1;
                break;
            }
        }
        if(flag) { print(-1, '\n'); continue; }
        if(ca[1]) {
            if(geta(1) != 1 && getb(1) != 1) {
                for(register int i = 3; i <= n; i += 2) {
                    if(geta(i) == 1) {
                        reverse(a + 1, a + i + 2);
                        ansa.push_back(i + 1);
                        break;
                    }
                }
            }
        }
        for(register int i = n - 1; i >= 1; i -= 2) {
            fprintf(stderr, "%d : \n%s\n%s\n", i, a + 1, b + 1);
            if(a[i] == b[i] && a[i + 1] == b[i + 1]) continue;
            if(geta(i) == 1 && (getb(i) == 0 || getb(i) == 2)) {
                int pos = -1;
                for(register int j = 1; j <= i - 2; j += 2) {
                    if(geta(j) == getb(i)) {
                        pos = j;
                        break;
                    }
                }
                reverse(a + 1, a + pos + 2); ansa.push_back(pos + 1);
                reverse(a + 1, a + i + 2); ansa.push_back(i + 1);
                continue;
            }
            if(getb(i) == 1 && (geta(i) == 0 || geta(i) == 2)) {
                int pos = -1;
                for(register int j = 1; j <= i - 2; j += 2) {
                    if(getb(j) == geta(i)) {
                        pos = j;
                        break;
                    }
                }
                reverse(b + 1, b + pos + 2); ansb.push_back(pos + 1);
                reverse(b + 1, b + i + 2); ansb.push_back(i + 1);
                continue;
            }
            if(geta(i) == getb(i)) {
                if(geta(1) == 1) {
                    if(a[1] == b[i]) {
                        swap(a[1], a[2]); ansa.push_back(2);
                    }
                    reverse(a + 1, a + i + 2); ansa.push_back(i + 1);
                } else {
                    if(b[1] == a[i]) {
                        swap(b[1], b[2]); ansb.push_back(2);
                    }
                    reverse(b + 1, b + i + 2); ansb.push_back(i + 1);
                }
                continue;
            }
            if(geta(1) == 1) {
                int pos = -1;
                for(register int j = 1; j <= i - 2; j += 2) {
                    if(getb(j) == geta(i)) {
                        pos = j;
                        break;
                    }
                }
                reverse(b + 1, b + pos + 2); ansb.push_back(pos + 1);
                reverse(b + 1, b + i + 2); ansb.push_back(i + 1);
            } else {
                int pos = -1;
                for(register int j = 1; j <= i - 2; j += 2) {
                    if(geta(j) == getb(i)) {
                        pos = j;
                        break;
                    }
                }
                reverse(a + 1, a + pos + 2); ansa.push_back(pos + 1);
                reverse(a + 1, a + i + 2); ansa.push_back(i + 1);
                continue;
            }
        }
        reverse(ansb.begin(), ansb.end());
        print((int)ansa.size() + (int)ansb.size(), '\n');
        for(register int i = 0; i < (int)ansa.size(); i++) print(ansa[i], ' ');
        for(register int i = 0; i < (int)ansb.size(); i++) print(ansb[i], ' ');
        putchar('\n');
    }
    return 0;
}