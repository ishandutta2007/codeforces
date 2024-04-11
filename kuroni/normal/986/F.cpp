#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MX = 32000000;
const long long INF = 1E18 + 7;

vector<int> pr;
map<long long, vector<long long>> fct, dst;
int t;
long long n, k;
bool chk[MX];

struct SNode
{
    long long u, val;
};

inline bool operator<(const SNode &a, const SNode &b)
{
    return a.val < b.val;
}
priority_queue<SNode, vector<SNode>, less<SNode>> pq;

void init()
{
    for (int i = 2; i < MX; i++)
        if (!chk[i])
        {
            pr.push_back(i);
            for (int j = i; j < MX / i; j++)
                chk[i * j] = true;
        }
}

void factorize(long long k)
{
    if (fct.find(k) != fct.end())
        return;
    vector<long long> &fact = fct[k];
    long long t = k;
    for (int &v : pr)
    {
        if (1LL * v * v > t)
            break;
        if (t % v == 0)
        {
            fact.push_back(v);
            while (t % v == 0)
                t /= v;
        }
    }
    if (t > 1)
        fact.push_back(t);
}

void Dijkstra(long long k)
{
    if (dst.find(k) != dst.end())
        return;
    vector<long long> &dist = dst[k], &fact = fct[k];
    long long pr = fact.front();
    dist = vector<long long>(pr, INF);
    for (pq.push((SNode){0, dist[0] = 0}); !pq.empty();)
    {
        SNode u = pq.top();
        pq.pop();
        for (long long &v : fact)
            if (dist[(u.u + v) % pr] > u.val + v)
                pq.push((SNode){(u.u + v) % pr, dist[(u.u + v) % pr] = u.val + v});
        while (!pq.empty() && dist[pq.top().u] < pq.top().val)
            pq.pop();
    }
}

void Euclid(long long a, long long b, long long *x, long long *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = n;
        return;
    }
    long long x1, y1;
    Euclid(b % a, a, &x1, &y1);
    *x = y1 - b / a * x1;
    *y = x1;
    if (b != 0)
    {
        *y -= ((*x % b + b) % b - *x) / b * a;
        *x = (*x % b + b) % b;
    }
}

void find_ans()
{
    factorize(k);
    if (fct[k].size() == 0)
        printf("NO\n");
    else if (fct[k].size() == 1)
        printf("%s\n", (n % k == 0 ? "YES" : "NO"));
    else if (fct[k].size() == 2)
    {
        long long a = fct[k][0], b = fct[k][1], x, y;
        Euclid(a, b, &x, &y);
        printf("%s\n", (y >= 0 ? "YES" : "NO"));
    }
    else
    {
        Dijkstra(k);
        printf("%s\n", (n >= dst[k][n % dst[k].size()] ? "YES" : "NO"));
    }
}

int main()
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        find_ans();
    }
}