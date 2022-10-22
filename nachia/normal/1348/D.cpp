#include <stdio.h>
#include <algorithm>
using namespace std;
using UL = unsigned int;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL T; scanf("%d", &T);
    while (T--) {
        UL N; scanf("%d", &N);
        UL day = 0;
        for (UL i = 0; i < 30; i++)
            if ((1u << i) <= N) day = i;
        UL D[100] = {};
        UL sum = day + 1;
        UL now = 1;
        for (UL i = 0; i < day; i++) {
            D[i] = min(now, (N - sum) / (day - i));
            sum += (day - i) * D[i];
            now += D[i];
        }
        printf("%d\n", day);
        rep(i, day) {
            if (i) printf(" ");
            printf("%d", D[i]);
        } printf("\n");
    }
    return 0;
}