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
const int MAXN = 1e5+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;
int f[MAXN];
void add(int pos,int x)
{
    for (;pos<MAXN;pos|=pos+1)
        f[pos]+=x;
}

int res(int l)
{
    int sum=0;
    for (;l>=0;l=((l+1)&l)-1)
        sum+=f[l];
    return sum;
}

int res(int l,int r)
{
    return res(r)-res(l-1);
}
void solve()
{
    int n;
    cin>>n;
    vector <int> ans(n);
    stack<int> s;
    stack<int> ss;
    for (int i=0;i<n;i++)
        add(i,1);
    int cur=0;
    rep(ii,2*n)
    {
        char c;
        cin>>c;
        if (c=='+')
            s.push(cur++),ss.push(-1);
        else
        {
            int x;
            cin>>x;
            x--;
            int val=res(x,n-1);
            add(x,-1);
            if (s.size()>val||s.empty())
            {
                cout<<"NO\n";
                return;
            }
            if (ss.top()>x)
            {
                cout<<"NO\n";
                return;
            }
            ans[s.top()]=x;
            s.pop();
            while (ss.top()!=-1){
                  if (ss.top()>x)
                        {
                              cout<<"NO\n";
                              return;
                        }
                ss.pop();
            }
            ss.pop();
            if (ss.size()>0)
                ss.push(x);
        }
    }
    cout<<"YES\n";
    for (auto to:ans)
        cout<<to+1<<" ";
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}