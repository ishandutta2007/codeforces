#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
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
    int n;
    cin>>n;
    vector <ll> a(n);
    rep(i,n)
    cin>>a[i];
    int i=0;
    map <ll,ll> m;
    int cnt=0;
    vector <ll> ans;
    bool ok=true;
    while (i<n&&ok)
    {
        map <ll,ll> k;
        int j=i;
    while (i<n&&(cnt||k.size()==0))
    {
        int x;
        x=a[i];
        if (x<0)
        {
            m[-x]--;
            if (m[-x]==0)
            cnt--;
            else
            {
                cout<<-1;
                return 0;
            }
        } else
        {
            m[x]++;
            if (m[x]==2)
            {
                cout<<-1;
                return 0;
            }
            else {
                cnt++;
                if (k[x]==1)
                {
                    cout<<-1;
                    //cout<<"ajja";
                    return 0;
                } else
                    k[x]=1;
            }
        }
        i++;
    }
    if (cnt==0) {
        ans.pb(i - j);
       if (i==n)
           ok=false;
    }
    else
    {
        cout<<-1;
        return 0;
    }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}