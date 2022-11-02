#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ALL(x) x.begin(), x.end()
typedef int _int;
#define int long long

struct mirror
{
    int l, r, cost;
    mirror (int _l=0, int _r=0, int _cost=0): l(_l), r(_r), cost(_cost) {}
};

bool cmp(mirror a, mirror b)
{
    return a.l < b.l;
}
       
vector<mirror> up, down;
int res=0;

_int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, hl, hr;
    cin >> hl >> hr >> n;
    
    for (int i=0; i<n; ++i)
    {
        int v, l, r;
        char c;
        cin >> v >> c >> l >> r;
        mirror cur = mirror(l, r, v);
        if (c != 'T')
            down.push_back(cur);
        else
            up.push_back(cur);
    }
    
    sort(ALL(up), cmp);
    sort(ALL(down), cmp);
    
    for (int _ = 0; _ < 2; ++_)
    {
        for (int cnt = 1; cnt <= 100; ++cnt)
        {
            int h = (cnt % 2 ? 100 - hr : hr);
            int a = hl + cnt*100 - h, b = 100*1000, c = -hl * b, lo = 0, bod = -100*cnt + h, uu = 0, dd = 0, i = 0, sum = 0, ok = true;
            while (lo > bod)
                if (i % 2 == 0)
                {
                    while (dd < down.size() && down[dd].r * a - b * i * 100 + c < 0)
                        ++dd;
                    if (dd == down.size() || down[dd].l * a - b * i * 100 + c > 0)
                        ok = false;
                    else
                        sum += down[dd++].cost;
                    ++i, lo -= 100;
                }
                else
                {
                    while (uu < up.size() && up[uu].r * a - b * i * 100 + c < 0)
                        ++uu;
                    if (uu == up.size() || up[uu].l * a - b * i * 100 + c > 0)
                        ok = false;
                    else
                        sum += up[uu++].cost;
                    ++i, lo -= 100;
                }
            if (ok)
                res = max(res, sum);
        }
        swap(up, down);
        hl = 100 - hl;
        hr = 100 - hr;
    }
        
    cout << res;
    
    return 0;
}