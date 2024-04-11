#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    set<int> t;

    bool ok = true;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;

        if (t.find(tmp) == t.end())
        {
            t.insert(tmp);
        }
        else
            ok = false;
    }

    cout << ((ok)? "NO\n":"YES\n");

}

int main()
{
    FAST;

    cin >> k;


    while(k--)
        solve();





    return 0;
}