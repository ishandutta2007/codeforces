#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100;

signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector <pair <int, pair <int, int> > > events;
    for(int i = 0; i < n; i++)
    {
        events.push_back({a[i], {1, i}});
        events.push_back({b[i], {-1, i}});
    }
    int ans = 0;
    sort(events.begin(), events.end());
    set <pair <int, int> > st1, st2;
    for(auto p : events)
    {
        int xa = a[p.Y.Y];
        int xb = b[p.Y.Y];
      //  cout << xa << " " << xb << " " << p.Y.X << "\n";
        set <pair <int, int> > :: iterator iter, iter1;
        if(p.Y.X== 1)
        {
            iter = st1.lower_bound({xb, 0});
            if(iter != st1.end())
            {
                ans = min(ans, xa -abs(xa - xb) - xb + iter -> Y);
            }
            iter = st2.lower_bound({-xb, 0});
            if(iter != st2.end())
            {
                ans = min(ans, xa -abs(xb - xa) + xb + iter -> Y);
            }
        }
        else
        {
            int f = -abs(xa - xb) + xa - xb;
            iter = st1.lower_bound({xa, -1e18});
            if(iter != st1.begin())
            {
                iter--;
                while(1)
                {
                    if(iter -> Y < f)
                    {
                        break;
                    }
                    iter1 = iter;
                    int fl = 0;
                    if(iter == st1.begin())
                    {
                        fl = 1;
                    }
                    iter1--;
                    st1.erase(iter);
                    if(fl)
                    {
                        break;
                    }
                    iter = iter1;
                }
            }
            iter = st1.lower_bound({xa, -1e18});
            if(iter == st1.end() || iter -> Y > f)
            {
                st1.insert({xa, f});
            }
            f = -abs(xa - xb) - xa - xb;
        //    cout << "B\n";
            iter = st2.lower_bound({-xa, -1e18});
            if(iter != st2.begin() && sz(st2) != 0)
            {
                iter--;
                while(1)
                {
                    //cout << "F\n";
                    //cout << sz(st2) <<"\n";
                    if(iter -> Y < f)
                    {
                        break;
                    }
                    iter1 = iter;
                    int fl = 0;
                    //cout << "OOPS\n";
                    if(iter == st2.begin())
                    {
                        fl = 1;
                    }
                    else
                    {
                  //      cout << "k\n";
                    iter1--;
                    }
                   // cout << "p\n";
                ///cout << iter -> X << " " << iter -> Y << "\n";
                    st2.erase(iter);
                    //cout << "E\n";
                    if(fl)
                    {
                        break;
                    }
                    iter = iter1;
                }
            }
 //           cout << "A\n";
            iter = st2.lower_bound({-xa, -1e18});
            if(iter == st2.end() || iter -> Y > f)
            {
                st2.insert({-xa, f});
            }
        }
    }
    st1.clear();
    st2.clear();
    reverse(events.begin(), events.end());
    for(auto p : events)
    {
        int xa = a[p.Y.Y];
        int xb = b[p.Y.Y];
      //  cout << xa << " " << xb << " " << p.Y.X << "\n";
        set <pair <int, int> > :: iterator iter, iter1;
        if(p.Y.X== 1)
        {
            iter = st1.lower_bound({xb, 0});
            if(iter != st1.end())
            {
                ans = min(ans, -xa -abs(xa - xb) - xb + iter -> Y);
            }
            iter = st2.lower_bound({-xb, 0});
            if(iter != st2.end())
            {
                ans = min(ans, -xa -abs(xb - xa) + xb + iter -> Y);
            }
        }
        else
        {
            int f = -abs(xa - xb) + xa + xb;
            iter = st1.lower_bound({xa, -1e18});
            if(iter != st1.begin())
            {
                iter--;
                while(1)
                {
                    if(iter -> Y < f)
                    {
                        break;
                    }
                    iter1 = iter;
                    int fl = 0;
                    if(iter == st1.begin())
                    {
                        fl = 1;
                    }
                    iter1--;
                    st1.erase(iter);
                    if(fl)
                    {
                        break;
                    }
                    iter = iter1;
                }
            }
            iter = st1.lower_bound({xa, -1e18});
            if(iter == st1.end() || iter -> Y > f)
            {
                st1.insert({xa, f});
            }
            f = -abs(xa - xb) - xa + xb;
        //    cout << "B\n";
            iter = st2.lower_bound({-xa, -1e18});
            if(iter != st2.begin() && sz(st2) != 0)
            {
                iter--;
                while(1)
                {
                    //cout << "F\n";
                    //cout << sz(st2) <<"\n";
                    if(iter -> Y < f)
                    {
                        break;
                    }
                    iter1 = iter;
                    int fl = 0;
                    //cout << "OOPS\n";
                    if(iter == st2.begin())
                    {
                        fl = 1;
                    }
                    else
                    {
                  //      cout << "k\n";
                    iter1--;
                    }
                   // cout << "p\n";
                ///cout << iter -> X << " " << iter -> Y << "\n";
                    st2.erase(iter);
                    //cout << "E\n";
                    if(fl)
                    {
                        break;
                    }
                    iter = iter1;
                }
            }
 //           cout << "A\n";
            iter = st2.lower_bound({-xa, -1e18});
            if(iter == st2.end() || iter -> Y > f)
            {
                st2.insert({-xa, f});
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
    }
    cout << ans;
    return 0;
}