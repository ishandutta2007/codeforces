#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
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

#define PII pair<int, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __div__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;


const long long MOD = 1000 * 1000 * 1000 + 7;

string s;
long long k;

long long pw(long long x, long long n)
{
    long long res = 1;
    for (; n > 0; n /= 2)
    {
        if (n % 2)
            res *= x, res %= MOD;
        x *= x, x %= MOD;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s >> k;
    long long one = 0;
    long long n = s.length();
    for (int i = 0; i < n; i++)
        if ((s[i] - '0') % 5 == 0)
            one += pw(2ll, i), one %= MOD;
    long long p = pw(2ll, n * k);
    p -= 1;
    p += MOD;
    p %= MOD;
    long long r = pw(2ll, n);
    r -= 1;
    r += MOD;
    r %= MOD;
    r = pw(r, MOD - 2);
    p *= r;
    p %= MOD;
    p *= one;
    p %= MOD;
    cout << p;

    return 0;
}