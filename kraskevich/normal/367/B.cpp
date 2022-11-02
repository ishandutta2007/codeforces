#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, m, p;
    cin >> n >> m >> p;
    vector<long long> a(n);
    vector<long long> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<long long> res;
    for (long long rem = 0; rem < p; rem++)
    {
        long long l = rem;
        long long r = rem + p * (m - 1);
        if (r >= n)
            continue;
        multiset<long long> toAdd;
        multiset<long long> toErase;
        for (auto x : b)
            toAdd.insert(x);
        for (long long i = l; i <= r; i += p)
            if (toAdd.find(a[i]) != toAdd.end())
                toAdd.erase(toAdd.find(a[i]));
            else
                toErase.insert(a[i]);
        if (toAdd.size() == 0 && toErase.size() == 0)
            res.push_back(l);
        r += p;
        for (; r < n; l += p, r += p)
        {
            if (toErase.find(a[l]) != toErase.end())
                toErase.erase(toErase.find(a[l]));
            else
                toAdd.insert(a[l]);
            if (toAdd.find(a[r]) != toAdd.end())
                toAdd.erase(toAdd.find(a[r]));
            else
                toErase.insert(a[r]);
            if (toAdd.size() == 0 && toErase.size() == 0)
                res.push_back(l + p);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto x : res)
        cout << x + 1 << " ";

    return 0;
}