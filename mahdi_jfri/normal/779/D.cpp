#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
string t , p;
int a[maxn] , last;
set<int> st[30];
set<int>::iterator it;
bool check(int x)
{
    if(last < x)
    {
        for(int i = last + 1; i <= x; i++)
            st[t[a[i]] - 'a'].erase(a[i]);
    }
    else
    {
        for(int i = last; i > x; i--)
            st[t[a[i]] - 'a'].insert(a[i]);
    }
    int l = t.size();
    bool f = 1;
    for(int i = p.size() - 1; i > -1 && f; i--)
    {
        if(!st[p[i] - 'a'].size())
        {
            f = 0;
            break;
        }
        it = st[p[i] - 'a'].upper_bound(l);
        it--;
        if(*st[p[i] - 'a'].begin() > l)
            f = 0;
        l = *it;
        l--;
    }
    last = x;
    return f;
}
ll bs(ll l , ll r)
{
    if(r - l == 1)
    {
        if(check(r))
            return r;
        return l;
    }
    ll mid = (r + l) / 2;
    if(check(mid))
        return bs(mid , r);
    else
        return bs(l , mid);
}
int main()
{
    cin >> t >> p;
    for(int i = 0; i < t.size(); i++)
    {
        st[t[i] - 'a'].insert(i);
        cin >> a[i];
        a[i]--;
    }
    last = -1;
    cout << bs(-1 , t.size() - 1) + 1;
}