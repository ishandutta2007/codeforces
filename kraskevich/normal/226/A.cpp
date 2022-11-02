#include <algorithm>
#include <iostream>
#include <string.h>
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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

int MOD;

int bin_pow(int b, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = res * 1ll * b % MOD;
        b = b * 1ll * b % MOD;
        n /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> MOD;

    cout << (bin_pow(3, n) - 1 + MOD) % MOD;

    return 0;
}