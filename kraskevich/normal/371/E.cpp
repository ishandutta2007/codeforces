#include <bits/stdc++.h>

using namespace std;

struct state
{
    long long x, id;

    void read(int i)
    {
        id = i;
        cin >> x;
    }
};

bool cmp(state a, state b)
{
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<state> a(n);
    for (int i = 0; i < n; i++)
        a[i].read(i + 1);
    int k;
    cin >> k;

    sort(a.begin(), a.end(), cmp);
    long long pref = 0;
    long long suff = 0;
    long long tot = 0;
    long long res = 0;
    int low = 0;
    for (int i = 0; i < k; i++)
        pref += a[i].x - a[0].x;
    for (int i = 0; i < k; i++)
        suff += a[k - 1].x - a[i].x;
    long long cur = 0;
    for (int i = 0; i < k; i++)
    {
        //cerr << a[i].x << endl;
        tot += i * a[i].x - cur;
        cerr << cur << " " << tot << endl;
        cur += a[i].x;
    }
    //cerr << endl;
    res = tot;
    cerr << res << "\n";
    //cerr << pref << " " << suff << endl;
    for (int l = 0, r = k; r < n; l++, r++)
    {
        tot -= pref;
        pref -= (a[l + 1].x - a[l].x) * (k - 1);
        pref += a[r].x - a[l + 1].x;
        suff -= (a[r - 1].x - a[l].x);
        suff += (a[r].x - a[r - 1].x) * (k - 1);
        tot += suff;
        cerr << tot << "\n";
        if (tot < res)
        {
            res = tot;
            low = l + 1;
        }
    }

    for (int i = low; i < low + k; i++)
        cout << a[i].id << " ";

    return 0;
}