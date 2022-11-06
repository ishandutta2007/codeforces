#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
long long l[N], r[N];

int main() {

    scanf("%d", &n);

    int sumL = 0, sumR = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &l[i], &r[i]);
        sumL += l[i];
        sumR += r[i];
    }

    long long bestCur = abs(sumL - sumR);
    int column = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(sumL - l[i] + r[i] - (sumR - r[i] + l[i])) > bestCur) {
            bestCur = abs(sumL - l[i] + r[i] - (sumR - r[i] + l[i]));
            column = i;
        }
    }

    printf("%d\n", column);

    return 0;
}