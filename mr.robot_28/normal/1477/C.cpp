#include<bits/stdc++.h>
using namespace std;
#define int long long
int dist(pair <int, int> a, pair <int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    vector <bool> used(n);
    vector <int> p;
    p.push_back(0);
    used[0] = 1;
    int en = 0;
    for(int it = 0; it < n - 1; it++)
    {
        int ind = -1;
        int ans1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(!used[i] && dist(x[en], x[i]) > ans1)
            {
                ans1 = dist(x[en], x[i]);
                ind = i;
            }
        }
        used[ind] = 1;
        p.push_back(ind);
        en = ind;
    }
    for(int i = 0; i < n; i++)
    {
        cout << p[i] + 1 << " ";
    }
    return 0;
}