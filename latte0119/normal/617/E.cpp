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

int N,Q,K;
int A[100000];
int S[111111];

vint sqrtSort(const vpint &vec,const int S){
    vector<pair<pint,int> >st(vec.size());
    rep(i,vec.size()){
        st[i].fi.fi=vec[i].fi/S;
        st[i].fi.se=vec[i].se;
        st[i].se=i;
    }
    sort(all(st));

    vint ret(vec.size());
    rep(i,vec.size())ret[i]=st[i].se;
    return ret;
}

signed main(){
    cin>>N>>Q>>K;
    rep(i,N)cin>>A[i];
    rep(i,N)S[i+1]=S[i]^A[i];


    vpint qs;
    rep(i,Q){
        int l,r;cin>>l>>r;l--;
        qs.pb(pint(l,r));
    }

    vint ord=sqrtSort(qs,300);

    int L=0,R=0,cur=0;
    vint cntL(1<<20),cntR(1<<20);
    vint ans(Q);

    rep(i,Q){
        int l=qs[ord[i]].fi,r=qs[ord[i]].se;

        while(l<L){
            L--;
            cntL[S[L]]++;
            cntR[S[L+1]]++;
            cur+=cntR[S[L]^K];
        }
        while(L<l){
            cur-=cntR[S[L]^K];
            cntL[S[L]]--;
            cntR[S[L+1]]--;
            L++;
        }
        while(r>R){
            cntL[S[R]]++;
            cntR[S[R+1]]++;
            cur+=cntL[S[R+1]^K];
            R++;
        }
        while(R>r){
            R--;
            cur-=cntL[S[R+1]^K];
            cntL[S[R]]--;
            cntR[S[R+1]]--;
        }
        ans[ord[i]]=cur;
    }

    rep(i,Q)cout<<ans[i]<<endl;
    return 0;
}