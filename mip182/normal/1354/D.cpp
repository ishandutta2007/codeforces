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


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int f[MAXN];
void add(int pos)
{
    for (;pos<MAXN;pos|=pos+1)
        f[pos]++;
}
void del(int pos)
{
    for (;pos<MAXN;pos|=pos+1)
        f[pos]--;
}
int res(int l)
{
    int sum=0;
    for (;l>=0;l=((l+1)&l)-1)
        sum+=f[l];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        add(x);
    }
    while (q--)
    {
        int k;
        cin>>k;
        if (k>0)
            add(k);
        else
        {
            k*=-1;
            int l=1,r=n;
            int ans=1;
            while (l<=r)
            {
                int mid=((l+r)>>1);
                if (res(mid)>=k)
                    ans=mid,r=mid-1;
                else
                    l=mid+1;
            }
            del(ans);
        }
    }
    int ans=0;
    int l=1,r=n;
    while (l<=r)
    {
        int mid=((l+r)>>1);
        if (res(mid)>=1)
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    cout<<ans;


}