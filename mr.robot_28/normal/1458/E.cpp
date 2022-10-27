#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
set <int> s;
int last;
int cnt;
bool flag;
map <pair <int, int>, int> mp;
void update(int add)
{
    int cnt = 0;
    while(s.size() > 0)
    {
        int x1 = *s.begin();
        if(last + add + cnt >= x1)
        {
            cnt++;
            s.erase(x1);
        }
        else
        {
            break;
        }
    }
    last += cnt + add;
}
bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
    if(a.first.first == b.first.first)
    {
        if(a.second == b.second)
        {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }
    return a.first.first < b.first.first;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > secret(n);
    vector <pair <pair <int, int>, int> > events;
    for(int i = 0; i < n; i++)
    {
        cin >> secret[i].first >> secret[i].second;
        mp[secret[i]] = 1;
        events.push_back({secret[i], 0});
    }
    vector <pair <int, int> > starts(m);
    for(int i = 0; i < m; i++)
    {
        cin >> starts[i].first >> starts[i].second;
        events.push_back({starts[i], i + 1});
    }
    events.push_back({{-1, -1}, 0});
    sort(events.begin(), events.end(), cmp);
    last = -1;
    s.insert(2e9);
    vector <int> ans(m);
    for(int i = 1; i < events.size(); i++)
    {
        if(events[i].second == 0)
        {
            flag = 0;
            update(events[i].first.first - events[i - 1].first.first);
            int min1 = 2e9;
            int j = i;
            while(j < events.size() && events[j].first.first == events[i].first.first && events[j].second == 0)
            {
                min1 = min(min1, events[j].first.second);
                if(events[j].first.second >= last)
                {
                    s.insert(events[j].first.second);
                }
                j++;
            }
            if(min1 <= last)
            {
                last--;
                flag = 1;
            }
            i = j - 1;
        }
        else
        {
            if(events[i].first.first != events[i - 1].first.first)
            {
                flag = 0;
            }
            update(events[i].first.first - events[i - 1].first.first);
            int j = i;
            while(j < events.size() && events[j].first.first == events[i].first.first)
            {
                if(mp[events[j].first] || (!flag && last == events[j].first.second))
                {
                    ans[events[j].second - 1] = 0;
                }
                else
                {
                    ans[events[j].second -1 ] = 1;
                }
                j++;
            }
            i = j - 1;
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(ans[i])
        {
            cout << "WIN\n";
        }
        else
        {
            cout << "LOSE\n";
        }
    }
    return 0;
}