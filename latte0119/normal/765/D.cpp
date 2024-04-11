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

int N;
int to[111111];
bool ok[111111];

vint g,h;

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&to[i]),to[i]--;

    rep(i,N)if(to[i]==i)ok[i]=true;

    rep(i,N)if(!ok[i]&&!ok[to[i]]){
        puts("-1");
        return 0;
    }

    g.resize(N);
    rep(i,N){
        if(ok[i]){
            g[i]=h.size();
            h.pb(i);
        }
    }
    rep(i,N){
        if(!ok[i]){
            g[i]=g[to[i]];
        }
    }

    printf("%lld\n",(int)h.size());
    rep(i,N)printf("%lld ",g[i]+1);puts("");
    rep(i,h.size())printf("%lld ",h[i]+1);puts("");
    return 0;
}