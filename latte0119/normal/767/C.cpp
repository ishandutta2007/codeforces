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
int T[1111111];
vint G[1111111];
int u;

int s[1111111];
int a[1111111];

signed main(){
    scanf("%lld",&N);
    int r;
    rep(i,N){
        int p;
        scanf("%lld%lld",&p,&T[i]);
        p--;
        if(p==-1)r=i;
        else G[p].pb(i);
    }

    int sum=accumulate(T,T+N,0ll);
    if(sum%3){
        puts("-1");
        return 0;
    }

    u=sum/3;

    vint ord={r};
    rep(i,N){
        int v=ord[i];
        for(auto u:G[v])ord.pb(u);
    }

    for(int i=N-1;i>=0;i--){
        int v=ord[i];
        s[v]=T[v];
        vint lis;
        for(auto u:G[v]){
            s[v]+=s[u];
            if(a[u]!=-1)lis.pb(a[u]);
        }
        if(lis.size()>=2){
            printf("%lld %lld\n",lis[0]+1,lis[1]+1);
            return 0;
        }
        if(lis.size()>=1&&s[v]==u*2&&i){
            printf("%lld %lld\n",lis[0]+1,v+1);
            return 0;
        }
        if(lis.size())a[v]=lis[0];
        else if(s[v]==u)a[v]=v;
        else a[v]=-1;
    }


    puts("-1");
    return 0;
}