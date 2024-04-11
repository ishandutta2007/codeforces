#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<0;
        return 0;
    }
    vector <int> p(n);
    int cnt1=0,cnt0=0;
    int chet=0;
    rep(i,n) {
        cin >> p[i];
        if (p[i]==0)
            chet++;
        else{
        if (p[i]%2==1)
            cnt1++;
        else
            cnt0++; }
    }
    if (chet==n)
    {
        cout<<1;
        return 0;
    }
    ll ans=0;
    for (int i=1;i<n;i++)
    {
        if ((p[i-1]%2)!=(p[i]%2)&&p[i]!=0&&p[i-1]!=0)
            ans++;
    }
    cnt1=(n+1)/2-cnt1,cnt0=n/2-cnt0;
    int i=0;
    vector <int> s,l,r;
    while (i<n)
    {
    if (p[i]>0) {
        i++;
        continue;
    }
    else
    {
        if (i==0)
            l.pb(-1);
        else
            l.pb(p[i-1]%2);
        int j=i;
        int cnt=0;
        while (j<n&&p[j]==0)
            j++,cnt++;
        if (j==n)
            r.pb(-1);
        else
            r.pb(p[j]%2);
        s.pb(cnt);
        i=j;
    }
    }
    vector <int> oneone,zeroone,onezero,zerozero;
    vector <pair <int,int> > inache;
    for (i=0;i<s.size();i++)
    {
        if (l[i]==1&&r[i]==1)
        {
            oneone.pb(s[i]);
            continue;
        }
        if (l[i]==0&&r[i]==0)
        {
            zerozero.pb(s[i]);
            continue;
        }
        if (l[i]==1&&r[i]==0)
        {
            onezero.pb(s[i]);
            continue;
        }
        if (l[i]==0&&r[i]==1)
        {
            onezero.pb(s[i]);
            continue;
        }
        inache.pb({s[i],max(l[i],r[i])});
    }
    sort(all(oneone));
    sort(all(zerozero));
    sort(all(onezero));
    ll a=-1,c=-1,d=-1,b=-1;
    sort(all(inache));
    for (i=0;i<inache.size();i++)
    {
        if (inache[i].second==0)
        {
            if (c==-1)
                c=inache[i].fi;
            else
                d=inache[i].fi;
        }
        else
        {
            if (a==-1)
                a=inache[i].fi;
            else
                b=inache[i].fi;
        }
    }
    int cur=0;
    while (cnt1>0)
    {
        if (cur==oneone.size())
            break;
        if (cnt1-oneone[cur]>=0)
        {
            cnt1-=oneone[cur];
            cur++;
        } else
            break;
    }
    int cur1=0;
    while (cnt0>0)
    {
        if (cur1==zerozero.size())
            break;
        if (cnt0-zerozero[cur1]>=0)
        {
            cnt0-=zerozero[cur1];
            cur1++;
        }
        else
            break;
    }
    ans+=(int)(onezero.size());
    if (a!=-1&&b!=-1)
    {
        if (a>b)
            swap(a,b);
    }
    if (c!=-1&&d!=-1)
    {
        if (c>d)
            swap(c,d);
    }
    int ok1=1,ok2=1,ok3=1,ok4=1;
    if (a!=-1)
    {
        if (cnt1>=a) {
            cnt1 -= a, ok1 = 0;
        }
    } else
        ok1=0;
    if (b!=-1)
    {
        if (cnt1>=b) {
            cnt1 -= b, ok2 = 0;
        }
    } else
        ok2=0;
    if (c!=-1)
    {
        if (cnt0>=c) {
            cnt0 -= c, ok3 = 0;
        }
    } else
        ok3=0;
    if (d!=-1)
    {
        if (cnt0>=d) {
            cnt0 -= d, ok4 = 0;
        }
    } else
        ok4=0;
    cout<<ans+ok1+ok2+ok3+ok4+((int)(oneone.size())-cur)*2+((int)(zerozero.size())-cur1)*2;






}