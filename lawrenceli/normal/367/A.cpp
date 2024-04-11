#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100100;

int n, m, bit[MAXN][3], arr[3];
char str[MAXN];

void update(int i, int j, int v) {
    for (i+=2; i<MAXN; i+=i&-i) bit[i][j] += v;
}

int query(int i, int j) {
    int ret = 0;
    for (i+=2; i>0; i-=i&-i) ret += bit[i][j];
    return ret;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s", str); n = strlen(str);
    for (int i=0; i<n; i++) {
        if (str[i] == 'x') update(i, 0, 1);
        else if (str[i] == 'y') update(i, 1, 1);
        else update(i, 2, 1);
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int l, r; scanf("%d %d", &l, &r); r--; l-=2;
        int len = r - l;
        if (len < 3) {
            printf("YES\n");
            continue;
        }
        bool good = 1;
        for (int j=0; j<3; j++) {
            arr[j] = query(r, j) - query(l, j);
            if (good && arr[j] != len / 3 && arr[j] != len / 3 + 1) {
                printf("NO\n");
                good = 0;
            }
        }
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (good && abs(arr[j] - arr[k]) > 1) {
                    printf("NO\n");
                    good = 0;
                }
            }
        }
        if (good) printf("YES\n");
    }
    return 0;
}