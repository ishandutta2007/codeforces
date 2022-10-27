#include<bits/stdc++.h>
using namespace std;
#define ll long long


signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    int n;
    ll C;
    cin >> n >> C;
    vector <ll> ww(n + 10), xx(n + 10);
    vector <int> rr(n + 10);
    vector <ll> aa(n + 10);
    vector <vector <int> > qu(2, vector <int> (n + 10));
    vector <int> cnt(2);
    for(int i = 2; i < n; i++)
    {
        cin >> ww[i];
        xx[i] = ww[i] - xx[i - 1];
    }
    for(int i = n - 1; i >= 1; i--)
    {
        int lower, upper;
        int p = i % 2;
        while(cnt[p] && xx[qu[p][cnt[p] - 1]] > xx[i])
        {
            cnt[p]--;
        }
        if(i + 1 < n)
        {
            rr[i + 1] = cnt[p] ? qu[p][cnt[p] - 1] : n;
        }
        qu[p][cnt[p]++] = i;
        lower = -1, upper = cnt[p ^ 1];
        while(upper - lower > 1)
        {
            int midd = (lower + upper) / 2;
            if(xx[qu[1 ^ p][midd]] > -xx[i])
            {
                upper = midd;
            }
            else
            {
                lower = midd;
            }
        }
        if(i + 1 < n && lower != -1)
        {
            rr[i + 1] = min(rr[i + 1], qu[1 ^ p][lower]);
        }
    }
    vector <int> same(n);
    vector <ll> dd;
    dd = ww;
    dd[1] = ww[2];
    for(int i = 2; i < n; i++)
    {
        if(i + 1 < n && ww[i] < ww[i + 1])
        {
            ll l, r, tmp;
            l = 0, r = ww[i];
            int j = i + 1;
            while(j < n)
            {
                tmp = l;
                l = ww[j] - r;
                r = ww[j] - tmp;
                if(r < 0)
                {
                    break;
                }
                if(l <= 0)
                {
                    dd[i] = (j - i) % 2 == 0 ? -(xx[j] - xx[i]) : xx[j] + xx[i];
                    i = j - 1;
                    goto next;
                }
                same[j++]=  1;
            }
            if(j == n)
            {
                break;
            }
            for(i++; i < j; i++)
            {
                if(j < rr[i])
                {
                    same[i] = 0;
                    while(j < rr[i])
                    {
                        same[j++] = 1;
                    }
                }
                if(j == n)
                {
                    goto out;
                }
                if(xx[rr[i]] - (rr[i] % 2 == (i - 1) % 2 ? xx[i - 1] : -xx[i - 1]) == 0)
                {
                    while(--j >= rr[i])
                    {
                        same[j] = 0;
                    }
                    same[i] = 0;
                    i = rr[i] - 1;
                    goto next;
                }
            }
            cout << "NO";
            return 0;
        }
        else
        {
            dd[i] = ww[i + 1];
        }
next:;
    }
out:
    int sgn = 1;
    for(int i = 1; i < n; ++i)
    {
        if(i > 1)
        {
            if(same[i])
            {
                dd[i] -= dd[i - 1];
            }
            else
            {
                sgn *= -1;
            }
        }
        aa[i] = aa[i - 1] + dd[i] * sgn;
    }
    ll _a = 0;
    for(int i = 0; i < n; i++)
    {
        _a = min(_a, aa[i]);
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
    {
        cout << aa[i] - _a << " ";
    }
    return 0;
}