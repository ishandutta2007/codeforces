#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> a;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    if (n == a)
    {
        for (int i = 0; i < n-1; ++i)
        {
            if (::data[i] > ::data[i+1])
            {
                cout << "NO" << endl;
                return 0;

            }
        }

        cout << "YES" << endl;
                return 0;
    }


    if (n-a > a-1)
    {
        cout << "YES" << endl;
                return 0;
    }


    vector<int> tmp;

    for (int i = 0; i < n-a; ++i)
    {
        tmp.push_back(::data[i]);
    }

for (int i = a; i < n; ++i)
    {
        tmp.push_back(::data[i]);
    }

    sort(tmp.begin(), tmp.end());


int l = tmp[tmp.size()/2-1];
int r = tmp[tmp.size()/2];

        if (::data[n-a] < l)
    {
                cout << "NO" << endl;
                return 0;

            }

    if (::data[a-1] > r)
        {
            cout << "NO" << endl;
            return 0;

        }

    for (int i = n-a; i < a-1; ++i)
        {
            if (::data[i] > ::data[i+1])
            {
                cout << "NO" << endl;
                return 0;

            }
        }


    cout << "YES" << endl;
                return 0;

    return 0;
}


int main()
{
    FAST;


    int t;
    cin >> t;
    while(t--)
        solve();




    return 0;
}