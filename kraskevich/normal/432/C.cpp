#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int N = 100 * 1000 + 10;

bool prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

set<int> p;

const int M = 500;
vector<int> dp[M];
vector<bool> is_pr(N);


vector<int> make(int n)
{
    if (n < M)
        return dp[n];
    for (int i = 1; i < M; i++)
    {
        int pp = n - i + 1;
        if (is_pr[pp])
        {
            vector<int> res = dp[i];
            res.push_back(pp);
            return res;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for (int i = 2; i < N; i++)
        if (prime(i))
        {
            is_pr[i] = true;
            p.insert(i);
        }
    for (int i = 0; i < 500; i++)
        if (is_pr[i])
            dp[i - 1].push_back(i);
    for (int rep = 0; rep < 4; rep++)
        for (int s = 0; s < M; s++)
        {
            if (dp[s].size() == 0)
                continue;
            for (set<int>::iterator it = p.begin(); ; it++)
            {
                if (*it + s - 1 >= M)
                    break;
                if (dp[s + *it - 1].size() == 0)
                {
                    dp[s + *it - 1] = dp[s];
                    dp[s + *it - 1].push_back(*it);
                }
            }
        }
    int L = 0;
    int R = 502;
    vector<int> v = make(R - L);
    int c = R;

    /*for (int x : v)
        {
            int r = c;
            int l = c - x + 1;
            //ans.push_back(pii(l + 1, r + 1));
            c = l;
            //pos[a[l]] = r;
            //pos[a[r]] = l;
            //swap(a[l], a[r]);
        }
        assert(c == L);*/

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    vector<pii> ans;
    for (int i = 0; i < n; i++)
    {
        int p = pos[i];
        if (p == i)
            continue;
        int d = p - i;
        vector<int> cur = make(d);
        int c = p;
        for (int x : cur)
        {
            int r = c;
            int l = c - x + 1;
            ans.push_back(pii(l + 1, r + 1));
            c = l;
            pos[a[l]] = r;
            pos[a[r]] = l;
            swap(a[l], a[r]);
        }
        assert(c == i);
    }

    cout << ans.size() << endl;
    for (pii x : ans)
        cout << x.F << " " << x.S << "\n";


    return 0;
}