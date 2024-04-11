#include <bits/stdc++.h>
using namespace std;
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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
int ask(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}

void solve()
{
    int n;
    cin>>n;
    int l=1,r=n;
    while (r-l+1>3)
    {
        int mid=((l+r)>>1);
        int x=ask(l,r);
        int y;
        if (x<=mid)
            y=ask(l,mid);
        else
            y=ask(mid+1,r);
        if (x==y)
        {
            if (x<=mid)
                r=mid;
            else
                l=mid+1;
        }
        else
        {
            if (x<=mid)
                l=mid+1;
            else
                r=mid;
        }
    }
    if (l==r)
    {
        cout<<"! "<<l<<endl;
        return;
    }
    if (r-l+1==2) {
        int x = ask(l, r);
        cout << "! " << l + r - x << endl;
    }
    else
    {
        int x=ask(l,r);
        if (x==l+1){
            int y=ask(l,l+1);
            if (y==x)
                cout<<"! "<<l<<endl;
            else
                cout<<"! "<<r<<endl;
        }
        else
        {
            int y;
            if (x==l)
            {
                y=ask(l,l+1);
                if (x==y)
                    cout<<"! "<<l+1<<endl;
                else
                    cout<<"! "<<r<<endl;
            }
            else
            {
                y=ask(r-1,r);
                if (x==y)
                    cout<<"! "<<l+1<<endl;
                else
                    cout<<"! "<<l<<endl;
            }
        }
    }
}

int main() {
    #ifdef Mip182
//    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}