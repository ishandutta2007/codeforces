#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXK = 55;

int k, x, n, m;
int dp[MAXK];

void process(int a, int b, int b1, int b2, int b3, int b4) {
    if (2*a+b1+b2 > n) return;
    if (2*b+b3+b4 > m) return;

    int xy = b2 && b3, yx = b1 && b4, yy = b3 && b4;

    dp[0] = a, dp[1] = b, dp[2] = a + b + xy;
    for (int i=3; i<k; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        if (i & 1) dp[i] += yx;
        else dp[i] += yy;

        if (dp[i] > x) return;
    }

    if (dp[k-1] != x) return;

    if (b1) cout << "C";
    for (int i=0; i<a; i++) cout << "AC";
    for (int i=2*a; i<n-b1-b2; i++) cout << "B";
    if (b2) cout << "A";
    cout << endl;

    if (b3) cout << "C";
    for (int i=0; i<b; i++) cout << "AC";
    for (int i=2*b; i<m-b3-b4; i++) cout << "B";
    if (b4) cout << "A";
    cout << endl;

    exit(0);
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> k >> x >> n >> m;

    for (int i=0; i<=n/2; i++)
        for (int j=0; j<=m/2; j++)
            for (int b1=0; b1<2; b1++)
                for (int b2=0; b2<2; b2++)
                    for (int b3=0; b3<2; b3++)
                        for (int b4=0; b4<2; b4++)
                            process(i, j, b1, b2, b3, b4);

    cout << "Happy new year!" << endl;
    return 0;
}