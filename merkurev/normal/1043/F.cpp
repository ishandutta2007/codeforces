#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 3e5 + 100;
int cnt[N], xcnt[N];
int reduce[N];
vector <int> ps[N];

int dist[N];
vector <int> qu;

int getVal(vector <int> &v, int mask)
{
    int ans = 1;
    for (int i = 0; i < (int) v.size(); i++)
        if (mask & (1 << i))
            ans *= v[i];
    return ans;
}

void gen(int v)
{
    int k = (int) ps[v].size();
    for (int mask = 0; mask < (1 << k); mask++)
    {
        int sum = 0;
        int nx = v / getVal(ps[v], mask);
//        eprintf("%d / %d : %d\n", v, getVal(ps[v], mask), nx);
        if (dist[nx] != 0) continue;
        for (int sb = mask; sb >= 0; sb = (sb - 1) & mask)
        {
            int md = v / getVal(ps[v], sb);
            int x = xcnt[md];
            if (__builtin_popcount(sb) % 2 != __builtin_popcount(mask) % 2)
                x = -x;
            sum += x;

            if (sb == 0) break;
        }
//        eprintf("v = %d, -> %d, mask = %d, sum = %d\n", v, nx, mask, sum);
        if (sum > 0)
        {
            dist[nx] = dist[v] + 1;
            qu.push_back(nx);
        }
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 2; i < N; i++)
    {
        if (ps[i].empty())
        {
            for (int j = i; j < N; j += i)
                ps[j].push_back(i);
        }
        long long x = i * 1LL * i;
        for (long long j = x; j < N; j += x)
            reduce[j] = j / i;
    }

    int cntGood = 0;
    for (int i = 0; i < N; i++)
        if (reduce[i] == 0)
            cntGood++;
    eprintf("%d\n", cntGood);


    double X = 0;
    for (int i = 2; i < N; i++)
        if (reduce[i] == 0)
        {
            X += pow(3, ps[i].size());
        }
    eprintf("X = %.10lf\n", X);


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        while (reduce[x])
            x = reduce[x];
//        eprintf("x = %d\n", x);
        cnt[x] = 1;
    }
    if (cnt[1] == 1)
    {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            xcnt[i] += cnt[j];
  
    for (int i = 0; i < 5; i++)
        eprintf("%d) %d %d\n", i, cnt[i], xcnt[i]);
   
    for (int i = 2; i < N; i++)
        if (cnt[i] > 0)
        {
            dist[i] = 1;
            qu.push_back(i);
        }

    for (int i = 0; i < (int) qu.size(); i++)
    {
        int v = qu[i];
        gen(v);
    }

    if (dist[1] == 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", dist[1]);

	return 0;
}