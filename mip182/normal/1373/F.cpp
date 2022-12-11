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

int n;
int ind(int x)
{
    if (x<0)
        x+=n;
    if (x>=n)
        x-=n;
    return x;
}
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
        cin>>n;
        vll a(n),b(n);
        rep(i,n)
        cin>>a[i];
        rep(i,n)
        cin>>b[i];
        int l=0,r=min(a[0],b[0]);
        bool ok=false;
        while (l<=r)
        {
            int mid=((l+r)>>1);
          //  cout<<mid<<'\n';
            vll c=a;
            vll d=b;
            c[0]-=mid;
            d[0]-=mid;
            d[n-1]-=c[0];
            c[0]=0;
            if (d[n-1]<0)
            {
                l=mid+1;
                continue;
            }
            int cur=0;
            bool ko=true;
            bool lol=true;
            while (true)
            {
                if (cur==n-2)
                {
                    if (d[cur]+d[cur+1]<c[cur+1])
                    {
                        lol=false;
                        break;
                    }
                    ok=true;
                    break;
                }
                else
                {
                    if (d[cur]+d[cur+1]<c[cur+1])
                    {
                        ko=false;
//                        for (auto to:d)
//                            cout<<to<<" ";
//                        cout<<'\n';
//                        for (auto to:c)
//                            cout<<to<<" ";
//                        cout<<'\n';
                        break;
                    }
                    c[cur+1]=max(0ll,c[cur+1]-d[cur]);
                    d[cur+1]-=c[cur+1];
                    c[cur+1]=0;
                    cur++;
                }
            }

            if (!ko)
            {
                r=mid-1;
                continue;
            }
            if (!lol)
            {
                l=mid+1;
                continue;
            }
            break;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}