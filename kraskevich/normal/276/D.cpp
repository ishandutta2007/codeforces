#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second


void solve()
{
    long long l, r;
    cin >> l >> r;

    int mx = -1;
    for (int i = 0; i < 62; ++i)
        if(((1ll<<i)&l)!=((1ll<<i)&r))
            mx=i;

    cout << (1ll<<(mx+1))-1;
}

int main()
{
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}