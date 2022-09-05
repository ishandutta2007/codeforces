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

const int N = 2005;

vector <pii> ans;
int a[N], id[N], tmp[N];
int n;

bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        id[i] = i;
    }
    while (n) {
        int cando = 1;
        for (int i = 1; i <= n; i++) {
            if (a[id[i]] == 0) {
                cando = 0;
                break;
            }
        }
        if (!cando) {
            int len = 0;
            for (int i = 1; i <= n; i++) {
                if (a[id[i]]) {
                    tmp[++len] = id[i];
                }
            }
            memcpy(id, tmp, (len + 1) * 4);
            n = len;
            continue;
        }
        if (n == 1) {
            print(-1, '\n');
            return 0;
        }
        sort(id + 1, id + n + 1, cmp);
        if (a[id[1]] == 1) {
            int pos = n;
            for (int i = n; i >= 2; i--) {
                if ((a[id[i]] & 1) && a[id[i]] > 1) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1 || (a[id[pos]] == 1 && n != 2)) {
                print(-1, '\n');
                return 0;
            }
            --a[id[1]]; --a[id[pos]];
            ans.push_back(make_pair(id[1], id[pos]));
        } else if (a[id[1]] == 2) {
            if (a[id[2]] != 2) {
                print(-1, '\n');
                return 0;
            }
            if (a[id[n]] == 2) {
                if (n == 2) {
                    print(-1, '\n');
                    return 0;
                }
                for (int i = 1; i <= n; i++) ans.push_back(make_pair(id[i], id[i % n + 1]));
                break;
            }
            a[id[1]] = a[id[2]] = 0; a[id[n]] -= 2;
            ans.push_back(make_pair(id[1], id[2]));
            ans.push_back(make_pair(id[1], id[n]));
            ans.push_back(make_pair(id[2], id[n]));
        } else {
            print(-1, '\n');
            return 0;
        }
    }
    print((int)ans.size(), '\n');
    for (int i = 0; i < (int)ans.size(); i++) {
        print(2, ' ');
        print(ans[i].first, ' ');
        print(ans[i].second, '\n');
    }
    return 0;
}