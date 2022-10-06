#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (v).size()
#define INF 1000000005
#define ll long long

using namespace std;

typedef vector<ll> vl;

int main()
{
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll sm = accumulate(all(a), 0LL);
    if(sm % k){
        cout << "No\n";
        return 0;
    }
    ll val = sm / k;
    ll nw = 0;
    vector<int> ans;
    int cnt = 0;
    rep(i,n){
        nw += a[i];
        cnt++;
        if(nw > val){
            cout << "No\n";
            return 0;
        }else if(nw == val){
            ans.pb(cnt);
            nw = cnt = 0;
        }
    }
    cout << "Yes\n";
    rep(i,k-1){
        cout << ans[i] << " ";
    }
    cout << ans[k-1] << "\n";
    return 0;
}