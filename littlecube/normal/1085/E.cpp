#include <bits/stdc++.h>
#define ll long lonh
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

void solve()
{
    int K, n, t[200] = {}, used[200] = {}, tt[200], tused[200];
    string s, a, b;
    cin >> K;
    cin >> s >> a >> b;
    n = s.size();
    if (b < a)
    {
        cout << "NO\n";
        return;
    }
    int i = 0;
    for (; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (t[s[i]] == 0 && !used[a[i]])
                t[s[i]] = a[i], used[a[i]] = 1;
            if (t[s[i]] != a[i])
            {
                cout << "NO\n";
                return;
            }
            continue;
        }
        else
            break;
    }
    if (i == n)
        goto ans;
    if (b[i] - a[i] >= 2)
    {
        if (t[s[i]])
        {
            if (a[i] < t[s[i]] && t[s[i]] < b[i])
                goto ans;
        }
        else
            for (int k = a[i] + 1; k < b[i]; k++)
                if (used[k] == 0)
                {
                    t[s[i]] = k;
                    used[k] = 1;
                    goto ans;
                }
    }

    if ((t[s[i]] == 0 && !used[a[i]]) || t[s[i]] == a[i])
    {
        for (int j = 'a'; j < 'a' + K; j++)
            tt[j] = t[j], tused[j] = used[j];
        tt[s[i]] = a[i], tused[a[i]] = 1;
        int j = i + 1;
        for (; j < n; j++)
        {

            if (tt[s[j]])
            {
                if (tt[s[j]] > a[j])
                {
                    for (int j = 'a'; j < 'a' + K; j++)
                        t[j] = tt[j], used[j] = tused[j];
                    // cout << 'a';
                    goto ans;
                }
                else if (tt[s[j]] == a[j])
                    continue;
                else
                    break;
            }
            else
            {
                for (int k = 'a' + K - 1; k > a[j]; k--)
                    if (!tused[k])
                    {
                        tt[s[j]] = k;
                        tused[k] = 1;
                        for (int j = 'a'; j < 'a' + K; j++)
                            t[j] = tt[j], used[j] = tused[j];
                        // cout << 'A' << j << (char)k;
                        goto ans;
                    }
                if (!tused[a[j]])
                {
                    tt[s[j]] = a[j];
                    tused[a[j]] = 1;
                }
                else
                    break;
            }
        }
        if (j == n)
        {
            for (int j = 'a'; j < 'a' + K; j++)
                t[j] = tt[j], used[j] = tused[j];
            goto ans;
        }
    }

    if ((t[s[i]] == 0 && !used[b[i]]) || t[s[i]] == b[i])
    {
        for (int j = 'a'; j < 'a' + K; j++)
            tt[j] = t[j], tused[j] = used[j];
        tt[s[i]] = b[i], tused[b[i]] = 1;
        int j = i + 1;
        for (; j < n; j++)
        {

            if (tt[s[j]])
            {
                if (tt[s[j]] < b[j])
                {
                    for (int j = 'a'; j < 'a' + K; j++)
                        t[j] = tt[j], used[j] = tused[j];
                    // cout << 'b';
                    goto ans;
                }
                else if (tt[s[j]] == b[j])
                    continue;
                else
                    break;
            }
            else
            {
                for (int k = 'a'; k < b[j]; k++)
                    if (!tused[k])
                    {
                        tt[s[j]] = k;
                        tused[k] = 1;
                        for (int j = 'a'; j < 'a' + K; j++)
                            t[j] = tt[j], used[j] = tused[j];
                        // cout << 'B';
                        goto ans;
                    }
                if (!tused[b[j]])
                {
                    tt[s[j]] = b[j];
                    tused[b[j]] = 1;
                }
                else
                    break;
            }
        }
        if (j == n)
        {
            for (int j = 'a'; j < 'a' + K; j++)
                t[j] = tt[j], used[j] = tused[j];
            goto ans;
        }
    }
    cout << "NO\n";
    return;
ans:
    for (int i = 'a', j = 'a'; i < 'a' + K; i++)
        if (t[i] == 0)
        {
            while (used[j])
                j++;
            used[j] = 1;
            t[i] = j;
        }

    cout << "YES\n";
    for (int i = 'a'; i < 'a' + K; i++)
        cout << (char)t[i];
    cout << '\n';
    for (int i = 0; i < n; i++)
        s[i] = t[s[i]];
    sort(t + 'a', t + 'a' + K);
    for (int i = 'a'; i < 'a' + K; i++)
        assert(t[i] == i);
    assert(a <= s);
    assert(s <= b);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}