#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

void solve()
{
    ll n, w, sum = 0, count = 0;
    cin >> n >> w;
    vector<pair<int, int>> a;
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        a.emplace_back(make_pair(tmp, i));
    }
    sort(a.begin(), a.end());
    int i = n;
    for (; i > 0; i--)
    {
        if (a.back().first > w)
            a.pop_back();
        else if (a.back().first > (w / 2))
        {
            b.emplace_back(a.back().second);
            a.pop_back();
            count++;
            sum = w;
            break;
        }
        else
        {
            sum += a.back().first;
            b.emplace_back(a.back().second);
            a.pop_back();
            count++;
            if (sum >= ((w + 1) / 2))
                break;
        }
    }
    sort(b.begin(), b.end());
    if (count == 0 || !(sum >= ((w + 1) / 2)))
    {
        cout << "-1\n";
        return;
    }
    cout << count << '\n';
    for (auto i : b)
        cout << i << " ";

    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}