#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, u;
long long ans = 0;
priority_queue<int> pq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &u); u -= i;
        ans -= u; pq.push(u); pq.push(u); // add the function of the current point
        ans += pq.top(); pq.pop(); // remove the 1-slope
    }
    printf("%lld", ans);
}