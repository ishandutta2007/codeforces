#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 2005;

int n, k;
int L[Maxn], R[Maxn], A[Maxn];
unordered_map <int, ll> dp[Maxn];

ll Solve(int ind, int b)
{
    if (ind >= n) return 0;
    auto it = dp[ind].find(b);
    if (it == dp[ind].end())
        if (A[ind] > b + ll(R[ind] - L[ind]) * k) {
            dp[ind].insert(make_pair(b, Inf));
            return Inf;
        } else {
            ll reloads = b >= A[ind]? 0: (A[ind] - b - 1) / k + 1;
            ll lft = b + reloads * k - A[ind];
            if (ind == n - 1 || L[ind] + reloads == L[ind + 1]) {
                ll res = A[ind] + Solve(ind + 1, lft);
                dp[ind].insert(make_pair(b, res));
                return res;
            } else {
                ll res = min(A[ind] + Solve(ind + 1, lft), A[ind] + lft + Solve(ind + 1, k));
                dp[ind].insert(make_pair(b, res));
                return res;
            }
        }
    return it->second;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &L[i], &R[i], &A[i]);
    ll res = Solve(0, k);
    if (res >= Inf) printf("-1\n");
    else cout << res << endl;
    return 0;
}