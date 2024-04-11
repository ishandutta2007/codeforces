#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n, m, s, f, t[MAXN], l[MAXN], r[MAXN], p, cur, dir;
char c;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d %d", &n, &m, &s, &f);
    for (int i=0; i<m; i++) scanf("%d %d %d", &t[i], &l[i], &r[i]);
    cur = s;
    if (s < f) {
        c = 'R';
        dir = 1;
    } else {
        c = 'L';
        dir = -1;
    }
    for (int i=1; cur != f; i++) {
        if (p<m && t[p] == i) {
            int nxt = cur + dir;
            if (cur >= l[p] && cur <= r[p] || nxt >= l[p] && nxt <= r[p]) {
                printf("X");
                p++;
            } else {
                printf("%c", c);
                cur = nxt;
                p++;
            }
        } else {
            printf("%c", c);
            cur = cur + dir;
        }
    }
}