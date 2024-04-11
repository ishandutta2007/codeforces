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

const int N = 15005;

vector < vector <int> > a[20];
vector <int> t1, t2;
vector <pii> ans;
int pos[20];
int n, cnt;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) a[0].push_back(vector <int> (1, i));
    for (int bit = 0; ; bit++) {
        if (a[bit].size() <= 1) break;
        while (a[bit].size() >= 2) {
            t1 = a[bit].back(); a[bit].pop_back();
            t2 = a[bit].back(); a[bit].pop_back();
            for (int i = 0; i < (1 << bit); i++) {
                ans.push_back(make_pair(t1[i], t2[i]));
                t1.push_back(t2[i]);
            }
            a[bit + 1].push_back(t1);
        }
    }
    for (int i = 0; i <= 14; i++) {
        if (a[i].size()) {
            pos[++cnt] = i;
        }
    }
    if (cnt > 2) {
        vector <int> now = a[pos[1]][0];
        for (int i = 2; i <= cnt - 1; i++) {
            while ((int)now.size() < (1 << pos[i])) {
                t1 = now;
                for (int j = 0; j < (int)now.size(); j++) {
                    int x = a[pos[cnt]][0].back();
                    a[pos[cnt]][0].pop_back();
                    ans.push_back(make_pair(now[j], x));
                    t1.push_back(x);
                }
                now = t1;
            }
            t1 = now;
            for (int j = 0; j < (int)now.size(); j++) {
                int x = a[pos[i]][0][j];
                ans.push_back(make_pair(now[j], x));
                t1.push_back(x);
            }
            now = t1;
        }
    }
    print((int)ans.size(), '\n');
    for (int i = 0; i < (int)ans.size(); i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
    return 0;
}