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

int main()
{
    ll n, K;
    cin >> n >> K;
    vector<ll> a(n);
    ll nw = 0, cnt = 0;
    rep(i,n){
        cin >> a[i];
        ll pre = nw;
        nw += a[i];
        ll rem = nw - nw/K*K;
        cnt += nw/K;
        if(nw/K*K < pre){
            rem = max(0LL,rem-(pre-nw/K*K+K-1)/K*K);
            cnt += (pre-nw/K*K+K-1)/K;
        }
        nw = rem;
    }
    cout << cnt+(nw+K-1)/K << "\n";
}