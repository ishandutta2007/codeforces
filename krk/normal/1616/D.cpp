#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 50005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];
ll sum[Maxn];
int x;
int nxt[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &x);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + ll(a[i] - x);
        deque <lli> D;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= 2) {
                while (!D.empty() && D.back().first <= sum[i - 2])
                    D.pop_back();
                D.push_back(lli(sum[i - 2], i - 1));
            }
            while (!D.empty() && D.front().first > sum[i]) {
                cur = D.front().second;
                D.pop_front();
            }
            nxt[i] = cur;
        }
        int v = n;
        int res = 0;
        while (v > 0) {
            res += v - nxt[v];
            v = nxt[v] - 1;
        }
        printf("%d\n", res);
    }
    return 0;
}