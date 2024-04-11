#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

struct point
{
       ll x, y;
       point(ll xx = 0, ll yy = 0)
       {
                x = xx;
                y = yy;
       }
       point operator - (const point & p)
       {
             return point(x - p.x, y - p.y);
       }
       ll operator * (const point & p)
       {
             return x * p.y - y * p.x;
       }
       point operator + (const point & p)
       {
             return point(x + p.x, y + p.y);
       }
};

bool cmp(point a, point b)
{
     return  a * b < 0;
}

vector<ll> best;

ll getX(point a, point b, int cnt)
{
        if(a.y == b.y)
               return -1;
        ll A = b.y - a.y, B = a.x - b.x, C = -(A * b.x + B * b.y);
        int l = -best.size() - 1, r = best.size() + 1;
        while(l < r - 1)
        {
                ll m = (l + r) / 2;
                if(m * A + C < 0)
                     l = m;
                else
                    r = m;
        }
        if(A * r + C <= 0)
             l = r;
        if(l >= 1 && l < best.size() && A * l + C == 0)
             best[l] = max(best[l], (ll)cnt + 1);
                
}
                  

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    
    cin >> n >> m;
    
    point p[m];
    
    for(int i = 0; i < m; ++i)
            cin >> p[i].x >> p[i].y;
    
    best.assign(n + 1, 1);
    
    for(int i = 0; i < m; ++i)
    {
            swap(p[0], p[i]);
            vector<point> v;
            for(int j = 1; j < m; ++j)
                    if(p[j].y < p[0].y)
                              v.push_back(p[j] - p[0]);
            sort(v.begin(), v.end(), cmp);
            int cur = 0;
            for(int j = 0; j < v.size(); ++j)
            {
                    ++cur;
                    if(j == v.size() - 1 || v[j] * v[j + 1] != 0)
                    {
                        getX(v[j] + p[0], p[0], cur);
                        cur = 0;
                    }
            }
            swap(p[i], p[0]);
    }
    
    ll ans = 0;
    
    for(int i = 1; i <= n; ++i)
    {
            ans += best[i];
    }
    
    cout << ans;
    
    return 0;
}