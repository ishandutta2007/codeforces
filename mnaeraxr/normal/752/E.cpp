#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 10000001;

int dp[maxn], T[maxn];
int cur = -1;

int solve(int a){
    if (T[a] == cur) return dp[a];
    T[a] = cur;

    if (cur > a) dp[a] = 0;
    else if (2 * cur > a) dp[a] = 1;
    else{
        int m = a / 2;
        dp[a] = solve(m) + solve(a - m);
    }

    return dp[a];
}

int main()
{
#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n;
    int64 k;
    scanf("%d%lld", &n, &k);

    vector<int> V(n);
    int64 sum = 0;


    for (int i = 0; i < n; ++i){
        scanf("%d", &V[i]);
        sum += V[i];
    }

    if (sum < k){
        printf("-1\n");
        return 0;
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    int lo = 1, hi = maxn;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;

        int64 tot = 0;
        cur = mid;

        if (sum < k * mid){
            hi = mid;
            continue;
        }

        for (int i = 0; i < n && tot < k; ++i)
            tot += solve( V[i] );

        if (tot >= k) lo = mid;
        else hi = mid;
    }

    printf("%d\n", lo);

    return 0;
}