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
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;

void solve()
{
    int n,k;
    cin>>n>>k;
    ll ans=0;
    string s;
    cin>>s;
    bool ok=false;
    vector <int> mx;
    int el=0;
    for (auto to:s)
    {
        if (to=='L')
        {
            ok=false;
            el++;
        }
        else
        {
            ans+=1+ok;
            ok=true;
        }
    }
    if (k==0)
    {
        cout<<ans<<'\n';
        return;
    }
    if (ans==2*(n-1)+1)
    {
        cout<<ans<<'\n';
        return;
    }
    if (ans==0)
    {
        cout<<2*(k-1)+1<<'\n';
        return;
    }
//    cout<<"ahha\n";
    int ind=0;
    int cnt=0;
    while (s[ind]!='W')
        cnt++,ind++;
    int ind1=n-1;
    int cnt1=0;
    while (s[ind1]!='W')
        cnt1++,ind1--;
//    ind1++;
//    cout<<ind<<" "<<ind1<<'\n';
    while (ind<=ind1)
    {
//        cout<<ind<<" "<<ind1<<" "<<n<<'\n';
        if (s[ind]=='W')
        {
            ind++;
            continue;
        }
        int chet=0;
        while (ind<=ind1&&s[ind]=='L')
            chet++,ind++;
        mx.pb(chet);
    }
//    cout<<"heh\n";
    sort(all(mx));
    for (auto to:mx)
    {
        if (k<to)
            break;
        ans+=2*to+1;
        k-=to;
        el-=to;
    }
    cout<<ans+2*min(k,el)<<'\n';

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}