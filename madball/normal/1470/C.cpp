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

#ifdef LOCAL
//#define INTERACTOR
int true_ans = 0;
#endif

vector<int> choices;
const int MAXN = (int)1e5 + 10;
int ar[MAXN];
int br[MAXN];
int n;

int ask(int i)
{
#ifdef INTERACTOR
    int a = ar[(i + n - true_ans) % n];
#else
    cout << '?' << ' ' << (i + 158454186) % n + 1 << endl;
    int a;
    cin >> a;
#endif
    For(j, sz(choices))
        if (ar[(i + n - choices[j]) % n] != a)
        {
            swap(choices[j], choices.back());
            choices.pop_back();
            --j;
        }
    memset(br, 0, sizeof(int) * n);
    br[1] = ar[0];
    for (int j = 1; j + 1 < n; ++j)
    {
        br[j - 1] += ar[j] / 2;
        br[j + 1] += (ar[j] + 1) / 2;
    }
    br[n - 2] += ar[n - 1] / 2;
    br[0] += (ar[n - 1] + 1) / 2;
    swap(ar, br);
    return a;
}

void answer(int i)
{
#ifdef INTERACTOR
    if (i != true_ans)
    {
        cout << "WA" << endl;
        throw;
    }
    else
        cout << "OK" << endl;
#else
    cout << '!' << ' ' << (i + 158454186) % n + 1 << endl;
#endif
    exit(0);
}

int aa(int i)
{
    int res = ask(i);
    if (sz(choices) == 1)
        answer(choices[0]);
    return res;
}

void ml()
{
#ifdef LOCAL
    cout << "ML" << endl;
    throw;
#endif
    vector<int> ar;
    while (true)
        ar.push_back(0);
}

void solve()
{
    int k;
    scanf("%d %d", &n, &k);
    For(i, n)
    {
        ar[i] = k;
        choices.push_back(i);
    }
    mt19937 rng(48);
#ifdef INTERACTOR
    true_ans = rng() % n;
#endif
    int l = -1, r = -1;
    For(_, 800)
    {
        int i = rng() % n;
        int cur = aa(i);
        if (cur > k)
            l = i;
        if (cur < k)
            r = i;
    }
    For(_, 125)
    {
        int i = (_ * 800) % n;
        int cur = aa(i);
        if (cur > k)
            l = i;
        if (cur < k)
            r = i;
    }

    if (l == -1 || r == -1)
        ml();
    while (min(l, r) + 1 < max(l, r))
    {
        int m = (l + r) / 2;
        if (aa(m) > k)
            l = m;
        else if (aa(m) < k)
            r = m;
        else
        {
            aa((m + n - 1) % n);
            aa(m % n);
            aa((m + 1) % n);
            aa((m + n / 2 + n - 1) % n);
            aa((m + n / 2) % n);
            aa((m + n / 2 + 1) % n);
            r = m;
        }
    }
    For(_, 1)
    {
        aa((l + n - 2) % n);
        aa((l + n - 1) % n);
        aa(l % n);
        aa((l + 1) % n);
        aa((l + 2) % n);
        aa((l + n / 2 + n - 2) % n);
        aa((l + n / 2 + n - 1) % n);
        aa((l + n / 2) % n);
        aa((l + n / 2 + 1) % n);
        aa((l + n / 2 + 2) % n);
    }
#ifdef LOCAL
    cout << "RE" << endl;
#endif
    while (sz(choices) > 10);
    answer(choices[rng() % sz(choices)]);
    //throw;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
#ifdef INTERACTOR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}