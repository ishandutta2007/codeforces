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

int acc[1000010];

signed main(){
    int N;
    scanf("%lld",&N);

    int ans=0;
    rep(i,N){
        int Q;
        scanf("%lld",&Q);
        ans^=Q;
    }

    for(int i=1;i<=N;i++){
        acc[i]=acc[i-1]^i;
        if((N/i)&1)ans^=acc[i-1];
        ans^=acc[N%i];
    }
    printf("%lld\n",ans);
    return 0;
}