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
#define pii pair<long long, long long>


const long long mod = 7340033;
const int S = 32;
const int K = 1001;
long long one[S][K];
long long two[S][K];

void init()
{
    for (int len = 0; len < S; ++len)
        for (int cnt = 0; cnt < K; ++cnt)
            one[len][cnt] = two[len][cnt] = (cnt == 0 ? 1 : 0);

    for (int len = 1; len < S; ++len)
    {
        for (int cnt1 = 0; cnt1 < K; ++cnt1)
            for (int cnt2 = 0; cnt2 + cnt1 < K - 1; ++cnt2)
                one[len][cnt1 + cnt2 + 1] += two[len - 1][cnt1] * two[len - 1][cnt2], one[len][cnt1 + cnt2 + 1] %= mod;
        for (int cnt1 = 0; cnt1 < K; ++cnt1)
            for (int cnt2 = (cnt1 == 0 ? 1 : 0); cnt1 + cnt2 < K; ++cnt2)
                two[len][cnt1 + cnt2] += one[len][cnt1] * one[len][cnt2], two[len][cnt1 + cnt2] %= mod;
    }
}



void solve()
{
    int n, k;
    cin >> n >> k;

    int l = 0;
    while (n % 2 == 1 && n >= 3)
        n /= 2, l++;

    cout << one[l][k] << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    init();

    int q;
    cin >> q;

    while (q--)
        solve();

    return 0;
}