#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = (int)1e5 + 10;
int ar[MAXN];
int br[MAXN];
int iar[MAXN];
int ibr[MAXN];
int res1[MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
    {
        scanf("%d", &ar[i]);
        --ar[i];
        iar[ar[i]] = i;
    }
    For(i, n)
    {
        scanf("%d", &br[i]);
        --br[i];
        ibr[br[i]] = i;
    }
    fill(res1, res1 + n, -1);
    static int kek1[MAXN], kek2[MAXN];
    For(i, n)
        kek1[i] = i % 2 ? n - 1 - i / 2 : i / 2;
    copy(kek1, kek1 + n, kek2);
    reverse(kek2, kek2 + n);
    int ptr1 = 0, ptr2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (res1[i] != -1)
            continue;
        static vector<int> loop;
        loop.clear();
        loop.push_back(i);
        do
        {
            loop.push_back(iar[br[loop.back()]]);
        } while (loop.back() != i);
        loop.pop_back();

        static vector<int> helper;
        helper.resize(sz(loop));
        For(j, sz(helper) - (sz(helper) % 2))
            helper[j] = kek1[ptr1++];
        if (sz(helper) % 2)
            helper[sz(helper) - 1] = kek2[ptr2++];
        For(j, sz(loop))
            res1[loop[j]] = helper[j];
    }
#ifdef LOCAL
    For(i, n)
        printf("%d%c", res1[i], (i + 1 == n ? '\n' : ' '));
    For(i, n)
        printf("%d%c", res1[iar[br[i]]], (i + 1 == n ? '\n' : ' '));
#endif
    lint res = 0;
    For(i, n)
        res += abs(res1[i] - res1[iar[br[i]]]);
    printf("%lld\n", res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}