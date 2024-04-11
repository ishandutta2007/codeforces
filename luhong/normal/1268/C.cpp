#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MN 201000

int n;
int a[MN], p[MN];
int c[MN];
std::priority_queue<int> pq1;
std::priority_queue<int, std::vector<int>, std::greater<int> > pq2;
long long sum1, sum2, sum3;

void add(int x) {for(int i = x; i <= n; i += i & -i) c[i]++;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

bool cmp(int x, int y) {return a[x] < a[y];}

int main()
{

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), p[i] = i;
    std::sort(p + 1, p + n + 1, cmp);
    pq1.push(0); pq2.push(n + 1);

    for(int i = 1; i <= n; i++)
    {
        int x = pq1.top(), y = pq2.top();
        if(p[i] < x)
        {
            pq1.push(p[i]); sum1 += p[i];
            if(!(i & 1)) pq1.pop(), pq2.push(x), sum1 -= x, sum2 += x;
        }
        else if(p[i] > y)
        {
            pq2.push(p[i]); sum2 += p[i];
            if(i & 1) pq2.pop(), pq1.push(y), sum2 -= y, sum1 += y;
        }
        else
        {
            if(i & 1) pq1.push(p[i]), sum1 += p[i];
            else pq2.push(p[i]), sum2 += p[i];
        }
        sum3 += (i - 1) - query(p[i]); add(p[i]);
        printf("%lld ", sum2 - sum1 + (i & 1 ? pq1.top() : 0) + sum3 - (i & 1 ? 1ll * (i + 1) * (i / 2) / 2 : 1ll * i * i / 4));
    }
}