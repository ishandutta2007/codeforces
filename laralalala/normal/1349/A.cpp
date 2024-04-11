#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int p[MAXN];
vector<int> fp[MAXN];
int a[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
    {
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
    }
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x);
    if(e&1)
        x=x*b;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        map<int,int> mm;
        while(a[i]!=1)
        {
            mm[p[a[i]]]++;
            a[i]/=p[a[i]];
        }

        for(auto y: mm)
            fp[y.first].push_back(y.second);
    }

    ll res=1;
    for(int i=2;i<MAXN;i++)
    {
        sort(all(fp[i]));
        if(fp[i].size()==n-1)
            res*=qp(i,fp[i][0]);
        else if(fp[i].size()==n)
            res*=qp(i,fp[i][1]);
    }
    db(res)

    return 0;
}