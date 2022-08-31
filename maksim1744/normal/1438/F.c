/*
    author:  Maksim1744
    created: 13.11.2020 18:36:40
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

unsigned rnd() {
    return (unsigned)rand() ^ ((unsigned)rand() << 8) ^ ((unsigned)rand() << 16) ^ ((unsigned)rand() << 24);
}

int cnt[1 << 19];

int main() {
    struct timeval tm;
    gettimeofday(&tm, NULL);
    srand(tm.tv_usec);

    int h;
    scanf("%d", &h);
    int n = (1 << h) - 1;
    for (int i = 0; i < n + 1; ++i) {
        cnt[i] = 0;
    }
    int allowed = 420 + 2;
    for (int i = 0; i < allowed; ++i) {
        int a = rnd() % n + 1;
        int b = a;
        int c = a;
        while (b == a) {
            b = rnd() % n + 1;
        }
        while (c == a || c == b) {
            c = rnd() % n + 1;
        }
        printf("? %d %d %d\n", a, b, c);
        fflush(stdout);
        int k;
        scanf("%d", &k);
        cnt[k]++;
    }

    int best[2];
    for (int i = 0; i < 2; ++i) {
        int ibest = 0;
        for (int j = 0; j < n + 1; ++j) {
            if (cnt[j] > cnt[ibest]) {
                ibest = j;
            }
        }
        best[i] = ibest;
        cnt[ibest] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == best[0] || i == best[1]) continue;
        printf("? %d %d %d\n", best[0], i, best[1]);
        fflush(stdout);
        int k;
        scanf("%d", &k);
        if (k != best[0] && k != best[1]) {
            printf("! %d\n", k);
            return 0;
        }
    }

    return 0;
}