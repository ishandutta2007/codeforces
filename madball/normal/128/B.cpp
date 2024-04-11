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
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int PRIME1 = (lint)1e4 + 7;
const int MOD1 = (lint)1e9 + 7;
const int PRIME2 = (lint)1e4 + 9;
const int MOD2 = (lint)1e9 + 9;
int pw1[100500];
int pw2[100500];

struct Hash
{
    int a, b;
    Hash(): a(0), b(0) {}
    Hash(int a, int b): a(a), b(b) {}
    Hash roll(char c) const
    {
        return Hash(((lint)a * PRIME1 + c) % MOD1, ((lint)b * PRIME2 + c) % MOD2);
    }
    Hash roll_many(int len) const
    {
        return Hash(((lint)a * pw1[len]) % MOD1, ((lint)b * pw2[len]) % MOD2);
    }
    Hash operator - (const Hash& other) const
    {
        Hash res(a - other.a, b - other.b);
        if (res.a < 0)
            res.a += MOD1;
        if (res.b < 0)
            res.b += MOD2;
        return res;
    }
    bool operator == (const Hash& other) const
    {
        return a == other.a && b == other.b;
    }
} hashes[100500];

Hash get_hash(int l, int r)
{
    if (r == 0)
        return Hash();
    if (l == 0)
        return hashes[r - 1];
    return (hashes[r - 1] - hashes[l - 1].roll_many(r - l));
}

char s[100500];

struct Substring
{
    int l, r;
    Substring() {}
    Substring(int l, int r) : l(l), r(r) {}
    bool operator < (const Substring& other) const
    {
        int le = 0;
        int ri = min(r - l, other.r - other.l) + 1;
        while (le + 1 < ri)
        {
            int m = (le + ri) / 2;
            if (get_hash(l, l + m) == get_hash(other.l, other.l + m))
                le = m;
            else
                ri = m;
        }
        if (le != min(r - l, other.r - other.l))
            return s[l + le] < s[other.l + le];
        else if (r - l != other.r - other.l)
            return r - l < other.r - other.l;
        else
            return l < other.l;
        /*int len = min(r - l, other.r - other.l);
        for (int i = 0; i < len; ++i)
            if (s[l + i] != s[other.l + i])
                return s[l + i] < s[other.l + i];
        if (r - l != other.r - other.l)
            return r - l < other.r - other.l;
        return l < other.l;*/
    }
};

set<Substring> st;

void solve()
{
    scanf("%s", s);
    pw1[0] = 1;
    pw2[0] = 1;
    hashes[0] = Hash(s[0], s[0]);
    For(i, 100499)
    {
        pw1[i + 1] = ((lint)pw1[i] * PRIME1) % MOD1;
        pw2[i + 1] = ((lint)pw2[i] * PRIME2) % MOD2;
        hashes[i + 1] = hashes[i].roll(s[i + 1]);
    }

    int k;
    scanf("%d", &k);
    int n = strlen(s);
    if (k > (lint)n * (n + 1) / 2)
    {
        printf("No such line.\n");
        return;
    }
    For(i, n)
        st.emplace(i, i + 1);
    For(i, k - 1)
    {
        Substring cur = *st.begin();
        st.erase(st.begin());
        if (cur.r < n)
            st.emplace(cur.l, cur.r + 1);
    }
    Substring res = *st.begin();
    for (int i = res.l; i < res.r; ++i)
        putchar(s[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}