#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


struct State
{
    long long cntX;
    long long lastX;
    
    State() : cntX(), lastX() {}

    State(long long _cntX, long long _lastX) : cntX(_cntX), lastX(_lastX) {}

    void eprint() const
    {
        eprintf("state: cntX = %lld, lastX = %lld\n", cntX, lastX);
    }
};

long long k;

State getCntLeq(long long pos)
{
    //eprintf("getCntLeq pos = %lld, k = %lld\n", pos, k);
    if (pos <= k * (k + 1) / 2)
    {
        //eprintf("easy\n");
        return State(0, 0);
    }
    if (pos == 4 && k == 2)
        return State(1, 3);
    long long bound = pos / k + (k + 2) / 2;
    State ns = getCntLeq(bound);
    long long nonX = bound - 1 - ns.cntX;
    long long rem = nonX % k;
    long long fst = bound - rem;
    if (fst <= ns.lastX)
        fst--;
    long long sum = fst * k + k * (k - 1) / 2;
    if (ns.lastX > fst)
        sum += k - (ns.lastX - fst);
    //eprintf("nonX = %lld, rem = %lld, fst = %lld\n", nonX, rem, fst);
   // eprintf("sum = %lld\n", sum);

    long long cntX = nonX / k + 1;
    
    while (fst > pos / k || sum >= pos)
    {
        cntX--;

        long long prv = fst - k;
        if (ns.lastX >= prv && ns.lastX < fst)
            prv--;
        long long psum = prv * k + k * (k - 1) / 2;
        if (ns.lastX >= prv && ns.lastX < fst)
            psum += k - (ns.lastX - prv);

        fst = prv;
        sum = psum;
    }
    //eprintf("fst = %lld, sum = %lld\n", fst, sum);

    long long lastX = sum;
    State ans = State(cntX, lastX);
    
    //ans.eprint();

    //eprintf("-----\n");
    return ans;
}


long long solve(long long n, long long _k)
{
    k = _k;
    
    State S = getCntLeq(n + 1);
    long long nonX = n - S.cntX;
    if (S.lastX == n)
        return S.cntX * (k + 1);
        
    long long ans = (nonX - 1) / k * (k + 1);
    ans += (nonX - 1) % k + 1;
    return ans;
}

void solve()
{
    long long n;
    long long _k;

    scanf("%lld%lld", &n, &_k);

    long long ans = solve(n, _k);

    printf("%lld\n", ans);
}


int main(int,  char **)
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}