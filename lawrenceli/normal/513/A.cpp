#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n1, n2, k1, k2;
int w[MAXN][MAXN][2];

int calc(int i, int j, int k) {
    int& ret = w[i][j][k];
    if (ret != -1) return ret;
    if (k == 0) {
        for (int l=1; l<=k1; l++)
            if (i-l>=0)
                if (!calc(i-l, j, 1)) return ret = 0;
    } else {
        for (int l=1; l<=k2; l++)
            if (j-l>=0)
                if (calc(i, j-l, 0)) return ret = 1;
    }
    return ret = !k;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n1 >> n2 >> k1 >> k2;
    memset(w, -1, sizeof(w));
    for (int i=0; i<MAXN; i++)
        w[0][i][0] = 1, w[i][0][1] = 0;
    if (calc(n1, n2, 0)) cout << "Second\n";
    else cout << "First\n";
    return 0;
}