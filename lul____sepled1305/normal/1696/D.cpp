#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 1<<18;

int n, t[4*N], mx[4*N], mi[4*N];

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int mini(int v, int tl, int tr, int l, int r) {
//    cout<<"R "<<l<<' '<<r<<endl;
    if (l > r)
        return 1e9;
    if (l == tl && r == tr) {
        return mi[v];
    }
    int tm = (tl + tr) / 2;
    return min(mini(v*2, tl, tm, l, min(r, tm))
           , mini(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int maxi(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return mx[v];
    }
    int tm = (tl + tr) / 2;
    return max(maxi(v*2, tl, tm, l, min(r, tm))
            , maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
        mi[v] = new_val;
        mx[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
        mi[v] = min(mi[v*2] , mi[v*2+1]);
        mx[v] = max(mx[v*2] , mx[v*2+1]);
    }
}

void solve(){
    int n; cin>>n;
    int p[n], a[n];
    vector<pii> st;
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        int k; cin>>k; a[i] = k;
        update(1,1,N,i+1,k);
        st.push_back({k,i});
        mp[k] = i;
    }
//    cout<<mini(1,1,N,2,2)<<endl;
    sort(st.begin(),st.end());
    //First and last can jump to any max
    stack<pii> st_mx; //max stack
    stack<pii> st_mi; //min stack
    for(int i=0;i<n;i++) {
        p[i] = max(0,i-1);
        while(!st_mx.empty() && st_mx.top().first < a[i]) {
            st_mx.pop();
        }
        while(!st_mi.empty() && st_mi.top().first > a[i]) {
            st_mi.pop();
        }
        int cap_mx;
        if(!st_mi.empty())
            cap_mx = st_mi.top().second;
        else
            cap_mx = 0;
        int cap_mi = 0;
        if(!st_mx.empty())
            cap_mi = st_mx.top().second;
        p[i] = min(p[i],mp[maxi(1,1,N,cap_mx+1,i+1)]);
        p[i] = min(p[i],mp[mini(1,1,N,cap_mi+1,i+1)]);
//        cout<<"N "<<i<<' '<<cap_mi<<' '<<cap_mx<<' '<<maxi(1,1,N,cap_mx+1,i+1)<<' '<<mini(1,1,N,cap_mi+1,i+1)<<endl;
        st_mx.push({a[i],i});
        st_mi.push({a[i],i});
    }
    int ct = 0;
    int runner = n-1;
    while(runner != 0) {
        runner = p[runner];
//        cout<<runner<<'\n';
        ct++;
    }
    cout<<ct<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T; // Comment this out if it is a single testcase
    while(T--)
        solve();
    return 0;
}