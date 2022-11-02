#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 401;
const int A = 160 * 1000 + 10;

int a[N][N];
int f[N];

short low[N][N];
short dp[N][N][N];

int rr[A];
int tt[A];
int fail[N];

int n, m;
int res = 1;

pii dq[N];
int head;
int tail;
int timer = 0;

void push(int val, int idx) {
    while (tail > head && dq[tail - 1].F <= val)
        tail--;
    dq[tail++] = pii(val, idx);
}

int getMax() {
    return dq[head].F;
}

void pop(int l) {
    if (dq[head].S <= l)
        head++;
}

void solve(int up) {
    fill(f, f + m, -1);
    fill(fail, fail + m, -1);
    for (int j = 0; j < m; j++) {
        timer++;
        for (int i = up; i < n; i++) {
            int v = a[i][j];
            if (tt[v] == timer) {
                fail[j] = i;
                break;
            }
            tt[v] = timer;
        }
    }
    for (int down = up; down < n; down++) {
        for (int j = 0; j < m; j++) {
            if (down == fail[j])
                f[j] = j;
            f[j] = max(f[j], (int)dp[j][down][up]);
        }
        head = 0;
        tail = 0;
        int l = 0;
        for (int r = 0; r < m; r++) {
            push(f[r], r);
            while (l <= r && getMax() >= l) {
                pop(l);
                l++;
            }
            if (l <= r)
                res = max(res, (down - up + 1) * (r - l + 1));
        }
    }
}

void calcLo(int j1, int j2) {
    timer++;
    if (j1 == j2)
        return;
    for (int i = 0; i < n; i++) {
        tt[a[i][j2]] = timer;
        rr[a[i][j2]] = i;
        if (tt[a[i][j1]] == timer)
            low[i][j2] = rr[a[i][j1]];
        else
            low[i][j2] = -1;
        if (i)
            low[i][j2] = max(low[i][j2], low[i - 1][j2]);
    }
    if (j1 > j2) {
        for (int i = 0; i < n; i++)
            if (low[i][j2] >= 0)
                dp[j1][i][low[i][j2]] = max((int)dp[j1][i][low[i][j2]], j2);
    } else {
        for (int i = 0; i < n; i++)
            if (low[i][j2] >= 0)
                dp[j2][i][low[i][j2]] = max((int)dp[j2][i][low[i][j2]], j1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    fill(rr, rr + A, 0);
    fill(tt, tt + A, 0);
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            for (int up = 0; up < n; up++)
                dp[j][i][up] = -1;

    for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++)
            calcLo(j1, j2);
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            for (int up = n - 2; up >= 0; up--)
                dp[j][i][up] = max(dp[j][i][up], dp[j][i][up + 1]);

    for (int i1 = 0; i1 < n; i1++)
        solve(i1);

    cout << res;

    return 0;
}