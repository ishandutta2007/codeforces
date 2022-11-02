#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 505;

char s[MAXN];
int N, K;
int val[MAXN][MAXN];
int dp[MAXN][MAXN], par[MAXN][MAXN];

int calc(int a, int b) {
    int ret = 0;
    for (int i=0; i<b-a; i++)
        if (s[i+a] != s[b-i-1]) ret ++;

    return ret / 2;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%s%d", s, &K);
    N = strlen(s);

    for (int i=0; i<N; i++)
        for (int j=i+1; j<=N; j++)
            val[i][j] = calc(i, j);

    for (int i=0; i<=N; i++)
        for (int j=0; j<=K; j++)
            dp[i][j] = 1e9;

    dp[0][0] = 0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            int& res = dp[i][j];
            int& p = par[i][j];
            res = 1e9;
            p = -1;

            for (int k=0; k<i; k++) {
                if (dp[k][j-1] == -1) continue;
                int num = dp[k][j-1] + val[k][i];
                if (res > num)
                    res = num, p = k;
            }

        }
    }

    int ans = 1e9, k = -1;
    for (int i=0; i<=K; i++)
        if (dp[N][i] < ans)
            ans = dp[N][i], k = i;

    printf("%d\n", ans);

    vector<int> v;
    int pnt = 0;

    int cur = N;
    while (cur != 0) {
        int p = par[cur][k];
        for (int i=0; i<cur-p; i++)
            if (s[i+p] != s[cur-i-1])
                s[i+p] = s[cur-i-1];

        cur = p;
        if (cur != 0) v.push_back(cur);
        k --;
    }

    reverse(v.begin(), v.end());

    for (int i=0; i<N; i++) {
        if (pnt < v.size() && v[pnt] == i) {
            printf("+");
            pnt++;
        }
        printf("%c", s[i]);
    }

    printf("\n");

    return 0;
}