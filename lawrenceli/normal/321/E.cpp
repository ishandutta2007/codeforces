#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXN = 4005;
const int MAXK = 805;
const int INF = 1e9;

int N, K, u[MAXN][MAXN], pre[MAXN][MAXN];
char str[2*MAXN];
int dp[MAXN][MAXK];
deque<int> dq;

int f(int i, int j, int k) {
    return dp[i][k]+pre[j][j]+pre[i][i]-2*pre[i][j];
}

int bs1(int a, int b, int k) {
    int lo = b+1, hi = N+1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(a, mid, k)-f(b, mid, k) >= 0) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int bs2(int c, int b, int k) {
    int lo = c, hi = N+1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(c, mid, k)-f(b, mid, k) <= 0) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    scanf("%d %d\n", &N, &K);
    for (int i=0; i<N; i++) {
        gets(str);
        for (int j=0; j<N; j++)
            u[i][j] = str[2*j]-'0';
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            pre[i+1][j+1] = u[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i][j];

    for (int i=0; i<=N; i++)
        for (int j=0; j<=K; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int k=1; k<=K; k++) {
        dq.clear();
        dq.push_back(0);
        for (int i=1; i<=N; i++) {
            while (dq.size()>1 && f(dq[0], i, k-1)>=f(dq[1], i, k-1)) dq.pop_front();
            while (dq.size()>1 && bs1(dq[dq.size()-2], dq.back(), k-1)>=bs2(i, dq.back(), k-1)) dq.pop_back();
            dq.push_back(i);
            dp[i][k] = f(dq[0], i, k-1);
        }
    }
    printf("%d\n", dp[N][K]/2);
    return 0;
}