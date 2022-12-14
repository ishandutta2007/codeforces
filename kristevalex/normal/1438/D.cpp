#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp;



int solve()
{
    cin >> n;

    vector<int> d (n);
    vector<int> ans;
    a = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
        a ^= d[i];
    }

    if (n%2 == 0 && a != 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        int maxi = 0;
        for (int i = 0; i + 2 < n; i+=2)
        {
            maxi = i;
            ans.push_back(i);
            ans.push_back(i+1);
            ans.push_back(i+2);
        }

        for (int i = maxi; i >= 0; i-=2)
        {
            maxi = i;
            ans.push_back(i);
            ans.push_back(i+1);
            ans.push_back(i+2);
        }

        cout << ans.size()/3 << endl;
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] + 1 << " ";
            if (i%3 == 2)
                cout << endl;
        }
    }





}

int main()
{
    FAST;

    solve();





    return 0;
}