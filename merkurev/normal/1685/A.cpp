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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}


void solve()
{

    int n;
    scanf("%d", &n);

    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector <int> ans;
    
    if (n % 2 == 1)
    {
        printf("NO\n");
        return;
    }

    for (int i = 0; i < n / 2; i++)
    {
        ans.push_back(v[i]);
        ans.push_back(v[n / 2 + i]);
    }
    ans.push_back(v[0]);
    for (int i = 0; i < n; i++)
        if (ans[i] == ans[i + 1])
        {
            printf("NO\n");
            return;
        }
    ans.pop_back();
    printf("YES\n");
    for (int x : ans)
        printf("%d ", x);
    printf("\n");
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