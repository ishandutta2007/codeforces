#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

long long ncr(long long n,long long r){
    if(r<0 || n<0 || n<r) return 0;
    if(r==0) return 1;
    if(r==1) return n;
    if(r==2) return (n*(n-1))/2;
    return (n*(n-1)*(n-2))/6;
}

struct node{
    long long int sum = 0;
};
struct SegmentTree{
    vector<node>t;
    long long int n;
    SegmentTree(vector<node>&arr){
        n = arr.size();
        t.resize(2*n+10);
        for(int i=0;i<n;i++) t[n+i] = arr[i];
        build(); 
    }
    SegmentTree(int _n){
        n = _n;
        t.resize(2*n + 10);
        build();
    }
    node combine(node a,node b){
        node ret;
        ret.sum = a.sum + b.sum;
        return ret;
    }
    
    void modify(int p,long long int value) { 
        for (t[p += n].sum = value; p > 1; p >>= 1) t[p>>1] = combine(t[p],t[p^1]);
    }

    void build(){
        for(long long int i=n-1;i>0;i--){
            t[i]=combine(t[i<<1],t[i<<1|1]);
        }
    }
    node query(long long int l,long long int r){
        node ret;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret=combine(ret,t[l++]);
            if(r&1) ret=combine(t[--r],ret);
        }
        return ret;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int t;cin>>t;
    pair<pii,long long int> q[t];
    for(int i=0;i<t;i++){
        cin>>q[i].F.F>>q[i].F.S;
        q[i].S = i;
    }
    sort(q,q+t);
    ll arr[200000+100]{0};
    for(int i=1;i<=200000;i++){
        for(int j=2*i;j<=200000;j+=i){
            arr[j]++;
        }
    }
    vector<node>fs(200000+10);
    for(int i=0;i<=200000;i++){
        fs[i].sum = ncr(arr[i],2);
    }
    SegmentTree segs(fs);
    int curr = 1;
    ll ans[t];
    for(auto i:q){
        while(i.F.F>curr){
            for(int j=2*curr;j<=200000;j+=curr){
                arr[j]--;
                segs.modify(j,ncr(arr[j],2));
            }   
            curr++;
        }
        long long int val  = (i.F.S/2)/3 - (i.F.F + 2)/3 + 1;
        long long int val2 = ((i.F.S*2)/5)/6 - (i.F.F + 5)/6 + 1;
        if(val<0)
            val = 0;
        if(val2<0)
            val2 = 0;    
        ans[i.S] = ncr(i.F.S-i.F.F+1,3) - segs.query(i.F.F,i.F.S+1).sum - val - val2;
    }
    for(auto i:ans){
        cout<<i<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}