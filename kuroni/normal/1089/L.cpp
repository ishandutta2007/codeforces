#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1e5 + 5;

struct work
{
    int t, p;
}   a[N];

int n, k, cnt[N];
stack <int> waiting;
long long ans = 0;

bool cmp(work a, work b)
{
    return a.p < b.p;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].t);
        cnt[a[i].t]++;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].p);
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= k; i++)
        if (cnt[i] == 0) waiting.push(i);
    for (int i = 1; i <= n; i++)
    {
        if (waiting.empty()) break;
        if (cnt[a[i].t] == 1) continue;
        ans += a[i].p;
        cnt[waiting.top()] = 1;
        cnt[a[i].t]--;
        waiting.pop();
    }
    printf("%I64d", ans);
	return 0;
}