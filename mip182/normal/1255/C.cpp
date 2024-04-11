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
  //  ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector <set <int> > m(n);
    for (int i=0;i<n-2;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--,c--;
        m[a].insert(b);
        m[a].insert(c);
        m[b].insert(c);
        m[b].insert(a);
        m[c].insert(a);
        m[c].insert(b);
    }
    int ind;
    for (int i=0;i<n;i++)
    {
        if (m[i].size()==2)
            ind=i;
    }
    vector <int> used(n,0);
    used[ind]=1;
    cout<<ind+1<<" ";
    int u,v;
    for (auto to:m[ind])
    {
        if (m[to].size()==3)
            u=to;
        else
            v=to;
    }
    cout<<u+1<<" ";
    used[u]=1;
    int cnt=2;
    vector <int> ans;
    ans.pb(ind);
    ans.pb(u);
    u=ind;
    while (cnt!=n)
    {
        cnt++;
        int x;
        for (auto to:m[u])
        {
            if (used[to]==0)
                x=to;
        }
        used[x]=1;
        u=x;
        cout<<u+1<<" ";
        ans.pb(u);
        u=ans[ans.size()-2];
    }
}