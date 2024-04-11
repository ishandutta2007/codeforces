#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 505;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf ("%d", &b[i]);
    int worst = 0;
    ll worst_ans = -1LL * inf * inf;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (1LL * a[i] * b[j] > worst_ans) {
                worst = i;
                worst_ans = 1LL * a[i] * b[j];
            }
    worst_ans = -1LL * inf * inf;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (1LL * a[i] * b[j] > worst_ans && i != worst) 
                worst_ans = 1LL * a[i] * b[j];
    printf("%I64d\n", worst_ans);
}