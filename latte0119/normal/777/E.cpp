#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

//RMQ
//INF
//
const int INF=1001001001001001001ll;
struct RMQ{
    static const int SIZE=1<<18;
    vector<int>dat;
    RMQ():dat(SIZE*2,INF){}
    void update(int k,int x){
        k+=SIZE-1;
        chmin(dat[k],x);
        while(k){
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=SIZE){
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return dat[k];
        return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

int N;
int A[111111],B[111111],H[111111];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%lld%lld",&A[i],&B[i],&H[i]);

    vint sz;
    sz.pb(0);
    rep(i,N){
        sz.pb(A[i]);
        sz.pb(B[i]);
    }
    sort(all(sz));
    sz.erase(unique(all(sz)),sz.end());
    rep(i,N){
        A[i]=lower_bound(all(sz),A[i])-sz.begin();
        B[i]=lower_bound(all(sz),B[i])-sz.begin();
    }

    vector<tuple<int,int,int>>ord;
    rep(i,N)ord.pb(make_tuple(B[i],A[i],i));
    sort(all(ord));
    reverse(all(ord));
    RMQ rmq;
    rmq.update(0,0);
    for(auto &lattemalta:ord){
        int i=get<2>(lattemalta);
        int tmp=-rmq.query(0,B[i])+H[i];
        rmq.update(A[i],-tmp);
    }

    cout<<-rmq.query(0,RMQ::SIZE)<<endl;
    return 0;
}