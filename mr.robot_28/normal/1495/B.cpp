#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
#define ld long double

set <int> st1, st2;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    map <int, int> mp;
    for(int i = 0; i < n; i++)
    {
        if((i == 0 || p[i - 1] > p[i]) && (i == n - 1 || p[i + 1] > p[i]))
        {
            st1.insert(i);
        }
        if((i == 0 || p[i - 1] < p[i]) && (i == n - 1 || p[i + 1] < p[i]))
        {
            st2.insert(i);
        }
    }
    int max1 = 0;
    for(auto id : st1)
    {
        set <int> :: iterator it;
        it = st2.lower_bound(id);
        if(it != st2.end())
        {
            mp[*it - id]++;
            max1 = max(max1, *it - id);
        }
        if(it != st2.begin())
        {
            it--;
            mp[id - *it]++;
            max1 = max(max1, id - *it);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || i == n - 1)
        {
            continue;
        }
        if(i != 0 && p[i - 1] > p[i])
        {
            continue;
        }
        if(i != n - 1 && p[i + 1] > p[i])
        {
            continue;
        }
        set <int> :: iterator it, it1;
        it = st1.lower_bound(i);
        it1 = it;
        if(it == st1.end() || it == st1.begin())
        {
            continue;
        }
        it1--;
        int d_r = *it - i;
        int d_l = i - *it1;
        if(d_l == d_r)
        {
            if(d_l % 2 == 0 && (d_l > max1 || d_l == max1 && mp[d_l] == 2))
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}