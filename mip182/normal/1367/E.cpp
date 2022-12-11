//#define _GLIBCXX_DEBUG
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <int> cnt(26);
        for (auto to:s)
            cnt[to-'a']++;
        sort(all(cnt));
        reverse(all(cnt));
        int ans=1;
        for (int i=n;i>1;i--)
        {
            vi a=cnt;
            bool ok=true;
            vector <int> sz,used(i);
            for (int j=0;j<i;j++)
            {
                if (used[j]==0)
                {
                    int x=j;
                    int chet=0;
                    while (used[x]==0)
                        chet++,used[x]=1,x+=k,x%=i;
                    sz.pb(chet);
                }
            }
            int cur=0;
            for (auto to:sz)
            {
                while (cur<26&&a[cur]<to)
                    cur++;
                if (cur==26)
                {
                    ok=false;
                    break;
                }
                a[cur]-=to;
            }
            if (ok)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<'\n';

    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}