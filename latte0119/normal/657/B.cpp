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

int N,K,A[222222];

int X[222222],Y[222222];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N+1)scanf("%lld",&A[i]);

    rep(i,N+1){
        if(A[i]>=0)X[i]+=A[i];
        else Y[i]+=-A[i];
    }

    rep(i,N+50){
        X[i+1]+=X[i]/2;
        X[i]%=2;

        Y[i+1]+=Y[i]/2;
        Y[i]%=2;
    }

    bool ok=true;
    for(int i=222221;i>=0;i--){
        if(X[i]&&!Y[i])break;
        if(!X[i]&&Y[i]){
            ok=false;
            break;
        }
    }

    if(!ok){
        rep(i,222222)swap(X[i],Y[i]);
        rep(i,N+1)A[i]*=-1;
    }

    bool up=false;
    rep(i,222221){
        if(up){
            X[i]--;
            up=false;
        }
        X[i]-=Y[i];
        if(X[i]<0){
            X[i]+=2;
            up=true;
        }
    }

    int mi=10101010101,ma=0;
    rep(i,222222){
        if(X[i]){
            chmin(mi,i);
            chmax(ma,i);
        }
    }

    int ans=0;
    for(int i=max(0ll,ma-40);i<=mi;i++){
        if(i>N)break;
        int a=0;
        for(int j=ma;j>=i;j--)a=(a<<1)+X[j];
        int aa=A[i]-a;
        if(aa<-K)continue;
        if(i==N&&A[i]==a)continue;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}