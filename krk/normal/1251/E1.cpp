#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int T;
int n;
ii p[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll cost = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].first, &p[i].second);
        sort(p, p + n);
        priority_queue <int> Q;
        for (int i = n - 1; i >= 0; i--) {
            Q.push(-p[i].second);
            while (i + cnt < p[i].first) {
                cost += -Q.top(); Q.pop();
                cnt++;
            }
        }
        printf("%I64d\n", cost);
    }
    return 0;
}