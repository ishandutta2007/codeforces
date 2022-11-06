#include <bits/stdc++.h>

using namespace std;

const int N = 500005, INF = 2e9 + 5;

int n, xo, yo;
int x[N], y[N];
char type[N];

int main() {

    scanf("%d", &n);
    scanf("%d %d", &xo, &yo);

    for (int i = 1; i <= n; i++) {
        scanf(" %c %d %d", &type[i], &x[i], &y[i]);
    }

    int leftUpDiag = -1;
    int bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] < xo && y[i] > yo && xo - x[i] == y[i] - yo && xo - x[i] < bs) {
            bs = xo - x[i];
            leftUpDiag = i;
        }
    }
    if (type[leftUpDiag] == 'B' || type[leftUpDiag] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int leftDownDiag = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] < xo && y[i] < yo && xo - x[i] == yo - y[i] && xo - x[i] < bs) {
            bs = xo - x[i];
            leftDownDiag = i;
        }
    }
    if (type[leftDownDiag] == 'B' || type[leftDownDiag] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int rightUpDiag = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] > xo && y[i] > yo && x[i] - xo == y[i] - yo && x[i] - xo < bs) {
            bs = x[i] - xo;
            rightUpDiag = i;
        }
    }
    if (type[rightUpDiag] == 'B' || type[rightUpDiag] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int rightDownDiag = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] > xo && y[i] < yo && x[i] - xo == yo - y[i] && x[i] - xo < bs) {
            bs = x[i] - xo;
            rightDownDiag = i;
        }
    }
    if (type[rightDownDiag] == 'B' || type[rightDownDiag] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int upCol = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] == xo && y[i] > yo && y[i] - yo < bs) {
            bs = y[i] - yo;
            upCol = i;
        }
    }
    if (type[upCol] == 'R' || type[upCol] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int downCol = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (x[i] == xo && y[i] < yo && -(y[i] - yo) < bs) {
            bs = -(y[i] - yo);
            downCol = i;
        }
    }

    if (type[downCol] == 'R' || type[downCol] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int leftRow = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (y[i] == yo && x[i] < xo && xo - x[i] < bs) {
            bs = xo - x[i];
            leftRow = i;
        }
    }
    if (type[leftRow] == 'R' || type[leftRow] == 'Q') {
        printf("YES\n");
        return 0;
    }

    int rightRow = -1;
    bs = INF;
    for (int i = 1; i <= n; i++) {
        if (y[i] == yo && x[i] > xo && x[i] - xo < bs) {
            bs = x[i] - xo;
            rightRow = i;
        }
    }
    if (type[rightRow] == 'R' || type[rightRow] == 'Q') {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    return 0;
}