#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct node {
    int v, pos;
    bool operator < (const node &A) const {
        if (v != A.v)
            return v < A.v;
        return pos < A.pos;
    }
} c[1001];

int n, a[1001], v[1001], r[1001][1001], w[1001];
bool b[1001][1001];
set < pair<int, int> > e;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[i].pos = i; c[i].v = a[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        v[c[i].pos] = i;
    for (int i = 1; i <= n; i++)
        w[v[i]] = i;
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j]) {
                ++cnt;
                b[i][j] = true;
             }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        bool ok = false;
        for (int j = 1; j <= n && !ok; j++) {
            if (v[j] != 1) {
                int x = w[v[j] - 1], y = j;
                if (x > y)
                    swap(x, y);
                if (b[x][y]) {
                    printf("%d %d\n", x, y);
                    ok = true;
                    b[x][y] = false;
                    swap(v[x], v[y]);
                    w[v[x]] = x; w[v[y]] = y;
                }
            }
        }
    } 
}