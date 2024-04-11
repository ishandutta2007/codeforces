#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        vector <ll> a(n);
        rep(i,n)
        cin>>a[i];
        int i=0,j=0;
        map <ll,ll> m;
        int ans=INF;
        int cnt=0;
        while (i<n)
        {
            while (j<n&&cnt==0)
            {
                m[a[j]]++;
                if (m[a[j]]==2)
                {   cnt++;
                    j++;
                    break;
                }
                j++;
            }
            if (cnt)
                ans=min(ans,j-i);
            m[a[i]]--;
            if (m[a[i]]==1)
                cnt--;
            i++;
        }
        if (ans==INF)
            cout<<-1;
        else
            cout<<ans;
        cout<<'\n';
    }
}