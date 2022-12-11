#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
    int n;
    cin>>n;
    vector <int> q(n);
    rep(i,n) {
        cin >> q[i];
        q[i]--;
    }
    vector <int> p(n,-1);
    p[0]=q[0];
   // cout<<q[0]<<" "<<p[0]<<'\n';
    vector <int > used(n,0);
    used[p[0]]=1;
    int i=0;
    while (i<n)
    {
        int j=i+1;
        while (j<n&&q[i]==q[j])
            j++;
        if (j!=n){
        p[j]=q[j];
        used[p[j]]=1;}
        i=j;
    }
   //for (int r=0;r<n;r++)
   //     cout<<p[r]<<" ";
   // cout<<'\n';
    i=0;
    vector <int > unused;
    for (int j=0;j<n;j++)
    {
        if (used[j]==0)
            unused.pb(j);
    }
    int j=0;
    while (i<n)
    {
    if (p[i]==-1)
        p[i]=unused[j],j++;
    i++;
    }
    bool ok=true;
    vector <int> pref(n);
    pref[0]=p[0];
    for (int x=1;x<n;x++)
        pref[x]=max(pref[x-1],p[x]);
    for (int x=0;x<n;x++)
    {
        if (pref[x]!=q[x])
            ok=false;
    }
    if (ok){
    for (int y=0;y<n;y++)
        cout<<p[y]+1<<" ";}
    else
        cout<<-1;
    cout<<'\n';


    }
}