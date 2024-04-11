#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;

ll ans = 0;
ll a, b;
int numa[22], numb[22];
int cnt[10], tcnt[10], tmp[10];
int lena = 0, lenb = 0;
inline ll read()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int main()
{
    a=read(), b = read();
    while(a)
    {
        numa[lena++] = a%10;
        a /= 10;
    }
    while(b)
    {
        numb[lenb++] = b%10;
        b /= 10;
    }
    reverse(numb, numb+lenb);
    if(lena < lenb)
    {
        sort(numa, numa+lena, greater<int>());
        rep(i, 0, lena-1) printf("%d", numa[i]);
        printf("\n");
        return 0;
    }
    ll now = 0;
    rep(i, 0, lena-1) cnt[numa[i]]++;
    rep(i, 0, lena-1)
    {
        rep(j, (i==0?1:0), numb[i]-1)
        {
            bool okay = true;
            rep(k, 0, 9)
            {
                if(tcnt[k]+(j==k)>cnt[k])
                    okay = false;
            }
            if (okay)
            {
                rep(k, 0, 9)
                {
                    tmp[k] = cnt[k]-(tcnt[k]+(j==k));
                }
                ll t = now*10+j;
                rep(k, i+1, lena-1)
                {
                    rrep(l, 9, 0)
                    {
                        if (tmp[l])
                        {
                            t *= 10; t += l;
                            tmp[l]--;
                            break;
                        }
                    }
                }
                ans = max(ans, t);
            }
        }
        tcnt[numb[i]]++;
        now *= 10; now += numb[i];
    }
    bool okay = true;
    rep(k, 0, 9)
    {
        if(tcnt[k]>cnt[k])
            okay = false;
    }
    if (okay) ans = max(ans, now);
    cout << ans << endl;
    return 0;
}