#include <bits/stdc++.h>

using namespace std;


const int N = 1000 * 1000 + 10;
vector<bool> p(N, 1);
vector<int> primes;

void seive()
{
    for (int i = 2; i * i < N; i++)
        if (p[i])
            for (int j = i * i; j < N; j += i)
                p[j] = 0;
    for (int i = 2; i < N; i++)
        if (p[i])
            primes.push_back(i);
}

int count(long long a)
{
    int res = 0;
    for (auto x: primes)
        while (a % x == 0)
        {
            res++;
            a /= x;
        }
    if (a > 1)
        res++;
    return res;
}

long long a[8], cnt[8];
long long have[8];
int par[8];
int res = N;
int n;

void upd()
{
    int cur = n;
    int root = 0;
    for (int i = 0; i < n; i++)
        if (par[i] == -1)
            root++;
    if (root > 1)
        cur++;
    for (int i = 0; i < n; i++)
        if (par[i] == -1)
            cur += cnt[i];
    for (int i = 0; i < n; i++)
        if (cnt[i] == 1)
            cur--;
    res = min(res, cur);
}

void solve(int pos)
{
    if (pos == n)
    {
        upd();
        return;
    }
    have[pos] = a[pos];
    par[pos] = -1;
    solve(pos + 1);
    for (int i = 0; i < pos; i++)
        if (have[i] % a[pos] == 0)
        {
            have[i] /= a[pos];
            par[pos] = i;
            solve(pos + 1);
            have[i] *= a[pos];
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    seive();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
        cnt[i] = count(a[i]);
    solve(0);
    cout << res;


    return 0;
}