#include <bits/stdc++.h>
#define int long long
using namespace std;

set<pair<int, int> > u, d;
int q;

int ccw(pair<int, int> x, pair<int, int> y, pair<int, int> z)
{
    int ax=y.first-x.first, ay=y.second-x.second;
    int bx=z.first-x.first, by=z.second-x.second;
    int res=ax*by-ay*bx;
    if(res>0)
    {
        return 1;
    }
    else if(res==0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

bool cu(pair<int, int> x)
{
    if(x==*u.begin()||x==*prev(u.end(), 1)) return true;
    auto it=u.lower_bound(x);
    if(it==u.begin()||it==u.end()) return false;
    if(ccw(x, *it, *prev(it, 1))==-1) return false;
    return true;
}

bool cd(pair<int, int> x)
{
    if(x==*d.begin()||x==*prev(d.end(), 1)) return true;
    auto it=d.lower_bound(x);
    if(it==d.begin()||it==d.end()) return false;
    if(ccw(x, *it, *prev(it, 1))==+1) return false;
    return true;
}

void add(int x, int y)
{
    if (u.size()<2) u.insert({x, y});
    else if(!cu({x, y}))
    {
        auto it=u.insert({x, y}).first;
        while(next(it, 2)!=u.end())
        {
            if(ccw(*it, *next(it, 1), *next(it, 2))>0)
            {
                u.erase(next(it, 1));
            }
            else
            {
                break;
            }
        }
        while(distance(u.begin(), it)>=2)
        {
            if(ccw(*it, *prev(it, 1), *prev(it, 2))<0)
            {
                u.erase(prev(it, 1));
            }
            else
            {
                break;
            }
        }
    }
    if (d.size()<2) d.insert({x, y});
    else if(!cd({x, y}))
    {
        auto it=d.insert({x, y}).first;
        while(next(it, 2)!=d.end())
        {
            if(ccw(*it, *next(it, 1), *next(it, 2))<0)
            {
                d.erase(next(it, 1));
            }
            else
            {
                break;
            }
        }
        //cout<<"ditme lai bug"<<endl;
        while(distance(d.begin(), it)>=2)
        {
            if(ccw(*it, *prev(it, 1), *prev(it, 2))>0)
            {
                d.erase(prev(it, 1));
            }
            else
            {
                break;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("prof.inp", "r", stdin);
    // freopen("prof.out", "w", stdout);
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int type, x, y;
        cin>>type>>x>>y;
        if(type==1)
        {
            add(x, y);
        }
        else
        {
            //cout<<type<<endl;
            //for(auto i:u) cout<<i.first<<" in u "<<i.second<<endl;
            //for(auto i:d) cout<<i.first<<" in d "<<i.second<<endl;
            if(cu({x, y})&&cd({x, y}))
            {
                cout<<"YES\n";
            }
            else
            {
                //cout<<cu({x, y})<<" "<<cd({x, y})<<endl;
                cout<<"NO\n";
            }
        }
    }
}