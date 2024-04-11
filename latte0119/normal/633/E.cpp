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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=1000000;
int N,K;
int v[SIZE],c[SIZE];
int ans[SIZE];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&v[i]),v[i]*=100;
    rep(i,N)scanf("%lld",&c[i]);
    deque<int>dv,dc;

    int r=0;
    rep(l,N){
        chmax(r,l);
        while(r<N){
            int mv=v[r];
            if(dv.size())chmax(mv,v[dv.front()]);
            int mc=c[r];
            if(dc.size())chmin(mc,c[dc.front()]);
            if(mv>=mc)break;
            while(dv.size()&&v[dv.back()]<=v[r])dv.pop_back();
            while(dc.size()&&c[dc.back()]>=c[r])dc.pop_back();
            dv.push_back(r);
            dc.push_back(r);
            r++;
        }
        if(dv.size()){
            chmax(ans[l],v[dv.front()]);
        }
        if(r!=N){
            int tmp=c[r];
            if(dc.size())chmin(tmp,c[dc.front()]);
            chmax(ans[l],tmp);
        }
        if(dv.size()&&dv.front()==l)dv.pop_front();
        if(dc.size()&&dc.front()==l)dc.pop_front();
    }

    sort(ans,ans+N);
    double t=1.0*K/N;
    double hoge=0;
    rep(i,N-K+1){
        if(i){
            t*=1.0*(N-K-i+1)/(N-i);
        }
        hoge+=t*ans[i];
    }

    printf("%.20f\n",hoge);
    return 0;
}