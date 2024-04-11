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

int N,M;
int p[3333333];
int a[3333333],b[3333333];

int to[3333333];
int mi[3333333];
signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N){
        scanf("%lld",&p[i]);
        to[--p[i]]=i;
    }
    fill_n(mi,N,N);

    rep(i,M){
        scanf("%lld%lld",&a[i],&b[i]);
        a[i]--;b[i]--;
        a[i]=to[a[i]];b[i]=to[b[i]];
        if(a[i]>b[i])swap(a[i],b[i]);
        chmin(mi[a[i]],b[i]);
    }
    for(int i=N-2;i>=0;i--)chmin(mi[i],mi[i+1]);

    int ans=0;
    rep(i,N){
        ans+=mi[i]-i;
    }
    printf("%lld\n",ans);
    return 0;
}