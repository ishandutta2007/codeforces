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

const int N = 5e4 + 5;

struct ele {
    int x, y, z, id;
    ele (int a = 0, int b = 0, int c = 0, int d = 0) : x(a), y(b), z(c), id(d) {}
    bool operator < (const ele A) const {
        if(x != A.x) return x < A.x;
        if(y != A.y) return y < A.y;
        return z < A.z;
    }
} a[N], b[N];

vector <ele> all;
int n;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i].x), read(a[i].y), read(a[i].z), a[i].id = i;
    sort(a + 1, a + n + 1);
    for(register int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while(r < n && a[r + 1].x == a[l].x) ++r;
        vector <ele> las;
        for(register int i = l, j; i <= r; i = j + 1) {
            j = i;
            while(j < r && a[j + 1].y == a[i].y) ++j;
            for(register int k = i + 1; k <= j; k += 2) {
                print(a[k - 1].id, ' '); print(a[k].id, '\n');
            }
            if((j - i + 1) & 1) las.push_back(a[j]);
        }
        for(register int i = 1; i < (int)las.size(); i += 2) {
            print(las[i - 1].id, ' '); print(las[i].id, '\n');
        }
        if((int)las.size() & 1) all.push_back(las[(int)las.size() - 1]);
    }
    for(register int i = 0; i < (int)all.size(); i += 2) print(all[i].id, ' '), print(all[i + 1].id, '\n');
    return 0;
}