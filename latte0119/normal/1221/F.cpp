#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

struct segtree{
    static const int SEG=1<<20;
    vector<pint>dat;
    vint put;
    segtree():dat(SEG*2),put(SEG*2){
        for(int i=0;i<SEG;i++)dat[i+SEG-1].se=i;
        for(int i=SEG-2;i>=0;i--)dat[i]=max(dat[i*2+1],dat[i*2+2]);
    }
    inline void push(int k){
        dat[k].fi+=put[k];
        if(k<SEG-1){
            put[k*2+1]+=put[k];
            put[k*2+2]+=put[k];
        }
        put[k]=0;
    }
    void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]+=x;
            push(k);
            return;
        }
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
    pint query(int a,int b,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return pint(-INF,-1);
        if(a<=l&&r<=b)return dat[k];
        return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

int N;
int L[555555],R[555555],C[555555];


vector<int>lis[1111111];
signed main(){
    scanf("%lld",&N);
    vector<int>vs;
    rep(i,N){
        scanf("%lld%lld%lld",&L[i],&R[i],&C[i]);
        if(L[i]>R[i])swap(L[i],R[i]);
        vs.pb(L[i]);vs.pb(R[i]);
    }
    sort(all(vs));vs.erase(unique(all(vs)),vs.end());
    rep(i,N){
        L[i]=lower_bound(all(vs),L[i])-vs.begin();
        R[i]=lower_bound(all(vs),R[i])-vs.begin();
        lis[L[i]].pb(i);
    }
    
    
    segtree seg;
    for(int i=0;i<vs.size();i++){
        seg.add(i,i+1,-vs[i]);
    }
    
    tuple<int,int,int>ans(0,1001001001,1001001001);
    
    for(int i=(int)vs.size()-1;i>=0;i--){
        for(auto j:lis[i]){
            seg.add(R[j],vs.size(),C[j]);
        }
        pint p=seg.query(i,vs.size());
        chmax(ans,make_tuple(p.fi+vs[i],vs[i],vs[p.se]));
    }
    
    cout<<get<0>(ans)<<endl;
    cout<<get<1>(ans)<<" "<<get<1>(ans)<<" "<<get<2>(ans)<<" "<<get<2>(ans)<<endl;
    return 0;
}