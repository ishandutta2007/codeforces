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

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int MAXN = (int)1e5 + 5;

/*struct Tree
{
    int ar[MAXN * 2];
    int n;
    Tree() {}
    void init(int n_)
    {
        n = n_;
        memset(ar, 0, sizeof(int) * n * 2);
    }
    void set(int i, int val)
    {
        i += n;
        ar[i] = val;
        for (i >>= 1; i; i >>= 1)
            ar[i] = gcd(ar[i * 2], ar[i * 2 + 1]);
    }
    int get(int l, int r) const
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = gcd(res, ar[l++]);
            if (r & 1)
                res = gcd(res, ar[--r]);
        }
        return res;
    }
} tree;*/

set<int>::iterator next_iter(const set<int>& st, set<int>::iterator it)
{
    ++it;
    if (it == st.end())
        it = st.begin();
    return it;
}

set<int>::iterator prev_iter(const set<int>& st, set<int>::iterator it)
{
    if (it == st.begin())
        it = st.end();
    --it;
    return it;
}

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> ar(n);
    set<int> songs;
    set<int> problems;
    For(i, n)
    {
        int a;
        scanf("%d", &a);
        ar[i] = a;
        songs.insert(i);
    }
    For(i, n - 1)
    {
        if (gcd(ar[i], ar[i + 1]) == 1)
        //if (tree.get(i, i + 2) == 1)
            problems.insert(i);
    }
    if (gcd(ar[0], ar[n - 1]) == 1)
    //if (gcd(tree.get(0, 1), tree.get(n - 1, n)) == 1)
        problems.insert(n - 1);
    int ptr = 0;
    vector<int> ans;
    while (!problems.empty())
    {
        auto it1 = problems.lower_bound(ptr);
        if (it1 == problems.end())
            it1 = problems.begin();
        int prev_song = *it1;
        int next_song = *next_iter(songs, songs.lower_bound(prev_song));
        ptr = next_song;
        songs.erase(next_song);
        ans.push_back(next_song);
        if (*next_iter(problems, it1) == next_song)
        {
            problems.erase(it1);
            problems.erase(next_song);
        }
        else
            problems.erase(it1);
        if (!songs.empty())
        {
            auto it2 = songs.lower_bound(prev_song);
            auto it3 = next_iter(songs, it2);
            if (gcd(ar[*it2], ar[*it3]) == 1)
                problems.insert(*it2);
        }
    }
    printf("%d", sz(ans));
    for (auto e : ans)
        printf(" %d", e + 1);
    printf("\n");
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