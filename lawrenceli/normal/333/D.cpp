#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
int a[MAXN][MAXN];
bool b[MAXN][MAXN], c[MAXN][MAXN];
int num[MAXN], cnt;

bool pos(int mid) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] >= mid) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            c[i][j] = 0;
    for (int j=0; j<m; j++) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (b[i][j]) num[cnt++] = i;
        }
        for (int i=0; i<cnt; i++) {
            for (int k=i+1; k<cnt; k++) {
                if (c[num[i]][num[k]]) return 1;
                c[num[i]][num[k]] = 1;
            }
        }
    }
    return 0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int lo = 0, hi = INF;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (pos(mid)) lo = mid;
        else hi = mid-1;
    }
    printf("%d\n", lo);
}