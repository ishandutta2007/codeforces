#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long int ll;
using namespace std;
void pre(){}
struct dat {
    long long int sum, pref, suff, ans;
};
dat t[4*100000];
dat combine(dat l, dat r) {
    dat res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
dat make_data(long long int val) {
    dat res;
    res.sum = val;
    res.pref = res.suff = res.ans = max((long long int)0, val);
    return res;
}

void build(long long int a[],long long int v,long long int tl,long long int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        long long int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(long long int v,long long int tl,long long int tr,long long int pos,long long int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        long long int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
dat query(long long int v,long long int tl,long long int tr,long long int l,long long int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    long long int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pii ref[n];
    ll freq[61]{0};
    for(int i = 0;i<61;i++){
        freq[i]=-1;
    }
    for(int i = 0;i<n;i++){
        ref[i].first=freq[arr[i]+30]+1;
        for(int j=0;j<arr[i]+30;j++){
            freq[j]=i;
        }
    }
    ll brr[n];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=brr[n-i-1];
    }
    for(int i = 0;i<61;i++){
        freq[i]=-1;
    }
    for(int i = 0;i<n;i++){
        ref[n-i-1].second=n-freq[arr[i]+30]-2;
        for(int j=0;j<arr[i]+30;j++){
            freq[j]=i;
        }
    }
    ll ans = 0;
    build(brr,1,0,n-1);
    for(int i=0;i<n;i++){
        //cout<<ref[i].first<<" "<<ref[i].second<<"\n";
        ans=max(ans,query(1,0,n-1,ref[i].first,i-1).suff+query(1,0,n-1,i+1,ref[i].second).pref);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}