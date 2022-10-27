#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <pair <int, int> > x(m);
        vector <int> cnt(n);
        int cnt1 = 0;
        vector <set <int> > st(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x[i].first >> x[i].second;
            x[i].first--;
            x[i].second--;
            if(x[i].first != x[i].second)
            {
                cnt1++;
            cnt[x[i].second]++;
            st[x[i].first].insert(i);
            cnt[x[i].first]++;
            st[x[i].second].insert(i);
            }
        }
        set <pair <int, int> > s;
        for(int i=  0; i < n; i++)
        {
            if(cnt[i] != 0)
            {
                s.insert({cnt[i], i});
            }
        }
        while(s.size() > 0)
        {
            pair <int, int> t = *s.begin();
            s.erase(s.begin());
            if(t.first == 2)
            {
            cnt1++;
            }
            int v = *st[t.second].begin();
            s.erase({cnt[x[v].first], x[v].first});
            s.erase({cnt[x[v].second], x[v].second});
            cnt[x[v].first]--;
            cnt[x[v].second]--;
            if(cnt[x[v].first] != 0)
            {
                s.insert({cnt[x[v].first], x[v].first});
            }
            if(cnt[x[v].second] != 0)
            {
                s.insert({cnt[x[v].second], x[v].second});
            }
            st[x[v].first].erase(v);
            st[x[v].second].erase(v);
        }
        cout << cnt1 << "\n";
    }
    return 0;
}