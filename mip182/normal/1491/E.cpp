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
const int MAXN = 2e5+1;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
int n;
int ind[2*MAXN];
int f[MAXN];
bool used[MAXN];
vector <vector<int> > g;
int vsego=0;
bool check(int i,int total)
{
//    cout<<i<<" "<<total<<'\n';
//            vsego++;
//        cout<<vsego<<'\n';
    if (total<=3)
        return true;
    if (ind[total]==-1)
        return false;
    int index=ind[total];
    int need1=f[index-2],need2=f[index-1];
//    int cnt_cut=0;
    function<pair <int,bool>(int,int)> go = [&](int s,int p)
    {
        int sum=1;
        for (auto to:g[s])
        {
            if (to==p||used[to])
                continue;
            auto f=go(to,s);
            sum+=f.fi;
            if (f.se)
                return mp(sum,true);
            if (f.fi==need1||f.fi==need2)
            {
//                cnt_cut++;
                if (f.fi!=need1) {
                    used[to]=true;
                    bool ok=check(s, (f.fi == need1 ? need2 : need1));
                    if (ok){
                        used[to]=false;
                        used[s]=true;
                        ok=check(to, f.fi);
                        if (ok)
                            return mp(sum,true);
                        else
                            used[s]=false;
                    }
                    else
                        used[to]=false;
                }
                else
                {
                    used[to]=true;
                    bool ok=check(s, (f.fi == need1 ? need2 : need1));
                    if (ok){
                        used[to]=false;
                        used[s]=true;
                        ok=check(to, f.fi);
                        if (ok)
                            return mp(sum,true);
                        else
                            used[s]=false;
                    }
                    else
                        used[to]=false;
                }
            }
        }
//        cout<<total<<" "<<sum<<" "<<s<<" "<<p<<'\n';
        return mp(sum,false);
    };
//    cout<<cnt_cut<<'\n';
    return go(i,i).se;
}
void solve()
{
    cin>>n;
    g=vector <vector<int> >(n);
    f[0]=1;
    f[1]=1;
    ind[1]=1;
    for (int i=0;i<MAXN;i++)
        ind[i]=-1;
    for (int now=2;;now++) {
        f[now] = f[now - 1] + f[now - 2];
        ind[f[now]]=now;
//        2
//        3
//        5
//        8
//        13
//        21
//        34
//        55
//        89
//        144
//        233
//        377
//        610
//        987
//        1597
//        2584
//        4181
//        6765
//        10946
//        17711
//        28657
//        46368
//        75025
//        121393
//        196418
//        317811
        if (f[now] > MAXN) {
            break;
        }
    }
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout<<(check(0,n)?"YES\n":"NO\n")<<'\n';
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
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