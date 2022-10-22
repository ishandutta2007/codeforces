#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair <int, int> ii;
 
int n, m;
int a[100005], c[100005];
priority_queue <ii, vector<ii>, greater<ii> > pq;
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < n; i++) pq.emplace(c[i], i);
    for (int i = 0; i < m; i++) {
        int t, j; scanf("%d%d", &t, &j);
        long long ans = 0;
        t--;
        if (a[t] >= j) {
            a[t] -= j;
            ans += (long long) c[t] * j;
            j = 0;
        } else {
            j -= a[t];
			 ans += (long long) c[t] * a[t];
            a[t] = 0;
            while (j > 0 && !pq.empty()) {
                int cost, cur; tie(cost, cur) = pq.top();
                if (a[cur] >= j) {
                    a[cur] -= j;
                    ans += (long long) c[cur] * j;
                    j = 0;
                } else {
                    j -= a[cur];
                    ans += (long long) a[cur] * c[cur];
                    a[cur] = 0;
                }
                if (a[cur]== 0) pq.pop();
            }
        }
        if (j != 0) printf("0\n");
        else printf("%lld\n", ans);
    }
    return 0;
}