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
    int t;
    cin>>t;
    while (t--) {

        ll n;
        cin>>n;
        ll wasn=n;
        bool ok=true;
        deque<pair <int,int> > primes;
        ll chet=0;
        for (ll jj=2;jj*jj<=n;jj++)
        {
            if (n%jj==0)
            {
                int cnt=0;
                while (n%jj==0)
                    cnt++,n/=jj;
                chet+=cnt;
                primes.pb({cnt,jj});
            }
        }
        if (n>1)
        {
            primes.pb({1,n});
            chet++;
        }
        if (primes.size()>=3)
        {
            ll q=1,qq=1;
            for (int i=0;i<primes[0].first;i++)
                q*=primes[0].se;
            cout<<"YES\n";
            for (int i=0;i<primes[1].first;i++)
                qq*=primes[1].se;
            cout<<q<<" "<<qq<<" "<<wasn/(q*qq)<<'\n';
        }
        else
        {
            if (primes.size()==2)
            {
            if (chet>3)
            {
                cout<<"YES\n";
                cout<<primes[0].se<<" "<<primes[1].se<<" "<<wasn/(primes[0].se*primes[1].se)<<'\n';
            } else
                cout<<"NO\n";
            }
            else
            {
                if (primes.size()==1)
                {
                    if (primes[0].fi>=6)
                    {
                        ll q=1;
                        q*=primes[0].se;
                        cout<<"YES\n";
                        cout<<q<<" "<<q*q<<" "<<wasn/(q*q*q)<<'\n';
                    }
                    else
                        cout<<"NO\n";
                }
                else
                {
                    cout<<"NO\n";
                }
            }
        }


    }




}