#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 1000005;

int n;
ll C;
ll need[Maxn], has[Maxn];
int pnt = -1;

int main()
{
    scanf("%d %I64d", &n, &C);
    for (int i = 1; i < 2 * n; i++) {
        scanf("%I64d", &need[i]);
        need[i] += need[i - 1];
    }
    priority_queue <lli> Q;
    Q.push(lli(has[0] - need[0], 0));
    for (int i = 1; i <= n; i++) {
        while (!Q.empty()) {
            int ind = Q.top().second;
            if (need[2 * i - 1] - need[2 * ind] >= C) {
                pnt = max(pnt, ind);
                Q.pop();
            } else break;
        }
        if (!Q.empty())
            has[i] = max(has[i], need[2 * i - 1] - has[i - 1] + Q.top().first);
        if (pnt >= 0)
            has[i] = max(has[i], C + has[pnt] - has[i - 1]);
        has[i] += has[i - 1];
        Q.push(lli(has[i] - need[2 * i], i));
    }
    cout << has[n] << endl;
    return 0;
}