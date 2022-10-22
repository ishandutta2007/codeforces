#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxn = 100005;
const ll Inf = 9000000000000000000ll;
 
int n, A, R, M;
int a[Maxn];
ll sum[Maxn];
ll res = Inf;
 
ll Solve(ll sumA, ll cntA, ll sumB, ll cntB, ll x)
{
    ll fir = x * cntA - sumA;
    ll sec = sumB - x * cntB;
    ll tk = min(fir, sec);
    ll res = tk * M; fir -= tk; sec -= tk;
    res += fir * A;
    res += sec * R;
    return res;
}
 
int main()
{
    scanf("%d %d %d %d", &n, &A, &R, &M);
    if (n == 1) { printf("0\n"); return 0; }
    M = min(M, A + R);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    ll p1 = sum[n] / n;
    ll p2 = p1 + 1ll;
    for (int i = 1; i < n; i++) {
        ll sumA = sum[i], cntA = i;
        ll sumB = sum[n] - sum[i], cntB = n - i;
        res = min(res, Solve(sumA, cntA, sumB, cntB, a[i]));
        res = min(res, Solve(sumA, cntA, sumB, cntB, a[i + 1]));
        if (a[i] <= p1 && p1 <= a[i + 1])
            res = min(res, Solve(sumA, cntA, sumB, cntB, p1));
        if (a[i] <= p2 && p2 <= a[i + 1])
            res = min(res, Solve(sumA, cntA, sumB, cntB, p2));
    }
    cout << res << endl;
    return 0;
}