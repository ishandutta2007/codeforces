#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=1e5+20;
vector<int>adj[maxn];
int a,b;
int c[maxn];
set<int>st[maxn];
int color=maxn , res[maxn] , _max=-1;
deque<int>dq;
map<int,int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        mp[c[i]]++;
        if(mp[c[i]] == 1)
            dq.push_back(c[i]);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        --a;
        --b;
        if(c[a] != c[b])
        {
            st[c[a]].insert(c[b]);
            st[c[b]].insert(c[a]);
        }
    }
    ll x = _max;
    _max = -1;
    for(int i = 0; i < dq.size(); i++)
    {
        res[dq[i]] = st[dq[i]].size();
        _max = max(res[ dq[i] ], _max);
    }
    for(int i = 0; i < dq.size(); i++)
    {
        if (res[dq[i]] == _max)
            color = min(color,dq[i]);
    }
    cout << color ;
}