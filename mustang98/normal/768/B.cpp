#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1;

map<ll, pair<ll, ll> > mapp;

// length, num1
pair<ll, ll> countt(ll n)
{
    pair<ll, ll> p;
    if (n == 1){
        p = mp(1, 1);
    } else if (n == 0) {
        p = mp(1, 0);
    }
    else {
        pair<ll, ll> lp = countt(n / 2);
        p = mp(lp.first * 2 + 1, lp.second * 2 + (n % 2));
    }
    mapp[n] = p;
    return p;
}

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    if (l > r)
    {
        cout << 0;
        return 0;
    }
    l--;
    countt(n);
    ll ansl = 0, ansr = 0;
    ll cur = n;
    pair<ll, ll> p;
    if (l != 0)
    {
        while(true)
        {
            p = mapp[cur];
            if (p.first == l) {
                ansl += p.second;
                break;
            }
            p = mapp[cur / 2];
            if (p.first + 1 == l)
            {
                ansl += p.second + cur % 2;
                break;
            }
            else if (l < p.first + 1)
            {
                cur = cur / 2;
                continue;
            }
            else
            {
                ansl += p.second + cur % 2;
                l -= p.first;
                l--;
                cur = cur / 2;
                continue;
            }
        }
    }
    cur = n;
    while(true)
    {
        p = mapp[cur];
        if (p.first == r) {
            ansr += p.second;
            break;
        }
        p = mapp[cur / 2];
        if (p.first + 1 == r)
        {
            ansr += p.second + cur % 2;
            break;
        }
        else if (r < p.first + 1)
        {
            cur = cur / 2;
            continue;
        }
        else
        {
            ansr += p.second + cur % 2;
            r -= p.first;
            r--;
            cur = cur / 2;
            continue;
        }
    }
    cout << ansr - ansl;

    return 0;
}