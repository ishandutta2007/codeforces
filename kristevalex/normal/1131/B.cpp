#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<pair<int, int>> data;

long long a, b, k, n, m, tmp, ans = 0;


int _get (int a1, int b1, int a2, int b2)
    {
    a1 = max(a1, b1);
    a2 = min(a2, b2);

    int d = a2-a1;

    return max(0, d+1);
    }


int main()
    {
    FAST;


    cin >> n;
    data.resize(n+1);
    data[0] = {-1, -1};

    for (int i = 1; i <= n; i++)
        {
        cin >> data[i].first >> data[i].second;

        }

    for (int i = 0; i < n; i++)
        {
        if (data[i] == data[i+1]) continue;

        ans+= _get(data[i].first, data[i].second, data[i+1].first, data[i+1].second);
        }

    for (int i = 1; i < n; i++)
        {
        if (data[i] == data[i+1]) continue;

        if (data[i].first == data[i].second) --ans;
        }

    cout << ans-1;

    return 0;
    }