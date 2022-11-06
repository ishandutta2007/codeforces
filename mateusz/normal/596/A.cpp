#include <bits/stdc++.h>

using namespace std;

const int N = 100005, C = 1005;

int n, x, y;
int cntX[2 * C + 10], cntY[2 * C + 10];

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        cntX[x + C]++;
        cntY[y + C]++;
    }

    vector<int> xx, yy;
    for (int i = 0; i <= 2010; i++) {
        if (cntX[i] > 0) {
            xx.push_back(i);
        }
        if (cntY[i] > 0) {
            yy.push_back(i);
        }
    }

    if (xx.size() == 2 && yy.size() == 2) {
        printf("%d", (xx[1] - xx[0]) * (yy[1] - yy[0]));
    } else {
        printf("-1");
    }

    return 0;
}