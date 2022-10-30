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


signed main(){
    int H,W;
    scanf("%lld%lld",&H,&W);
    vector<vint> A(H,vint(W)),T(H,vint(W));
    rep(i,H)rep(j,W)scanf("%lld",&A[i][j]);

    rep(j,W)T[H-1][j]=1;
    vint latte(H);
    for(int i=H-2;i>=0;i--){
        rep(j,W){
            if(A[i][j]<=A[i+1][j])T[i][j]=T[i+1][j]+1;
            else T[i][j]=1;
        }
    }

    rep(i,H){
        latte[i]=0;
        rep(j,W)chmax(latte[i],T[i][j]);
    }

    int Q;scanf("%lld",&Q);
    while(Q--){
        int l,r;
        scanf("%lld%lld",&l,&r);
        l--;
        if(latte[l]>=r-l)puts("Yes");
        else puts("No");
    }
    return 0;
}