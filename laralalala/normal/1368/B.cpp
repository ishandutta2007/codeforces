#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

ll f10(ll x)
{
    ll res=1;
    for(int i=0;i<10;i++)
        res*=x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;
    ll res=1;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=0;i<10;i++)
        pq.push(pii(1,i));
    while(res<k)
    {
        pii x=pq.top();
        pq.pop();
        ll p=x.s;
        ll v=x.f;
        res/=v;
        res*=(v+1);
        pq.push(pii(v+1,p));
    }

    string c="codeforces";
    int f[10];
    while(!pq.empty())
    {
        f[pq.top().s]=pq.top().f;
        pq.pop();
    }

    for(int i=0;i<10;i++)
        for(int j=0;j<f[i];j++)
            cout << c[i];
    cout << '\n';

    return 0;
}