#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

vector<int> v[max_n];

int main()
{
    int n;
    cin >> n;
    int m[max_n];
    int ans[max_n];
    int r = n - 1;

    int a;
    for (int i= 0; i < n; ++i)
    {
        cin >> a;
        m[a] = i;
    }

    ans[n] = m[n];
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(m[i], ans[i + 1]);
    }


    for (int i = 1; i <= n; ++i)
    {
        v[ans[i]].pb(-i);
    }

    for (int i = 0; i < n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        for (int to : v[i])
        {
            cout << -to << ' ' ;
        }
        cout << endl;
    }

    return 0;
}