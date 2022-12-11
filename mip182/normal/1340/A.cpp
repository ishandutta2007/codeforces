//#define _GLIBCXX_DEBUG
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
#define vvll vector <vll>
#define vsi vector <si>
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
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector <int> p(n);
        for (int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            x--;
            p[x]=i;
        }
        set <pair <int,int> > s;
        for (int i=0;i<n;i++)
            s.insert({-1,i});
//        s.insert({0,-1});
//        s.insert({0,n});
        vector <int> cnt(n+1,1);
        set <int> now;
        for (int i=0;i<n;i++)
            now.insert(i);
        now.insert(-1);
        now.insert(n);
        bool ok=true;
        for (int i=0;i<n;i++)
        {
            int g=cnt[p[i]];
            if (g==-((*s.begin()).fi))
            {
                auto to=now.find(p[i]);
                auto too=prev(to);
                auto f=next(to);
             //   cout<<*too<<" "<<*to<<" "<<*f<<'\n';
                s.erase({-g,p[i]});
                cnt[p[i]]=0;
                int x=*f-*too;
                if (*f!=n) {
                    s.erase({-cnt[*f], *f});
                    cnt[*f] = x;
                    s.insert({-cnt[*f], *f});
                }
                now.erase(to);
//                for (auto tooo:now)
//                    cout<<tooo<<" ";
//                cout<<'\n';
//                for (int j=0;j<n;j++)
//                    cout<<cnt[j]<<" ";
//                cout<<'\n';



            }
            else
            {
                ok=false;
                break;
            }
        }
        if (ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";




    }




}