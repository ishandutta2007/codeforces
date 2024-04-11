#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};

vint G[33];
int ansy[33],ansx[33];

bool solve(int v,int p,int y,int x,int w,int pd){
    int d=0;
    ansy[v]=y;ansx[v]=x;
    bool ok=true;
    for(auto u:G[v]){
        if(u==p)continue;
        if(d==pd)d++;
        if(d>=4)return false;
        int ny=y+w/4*3*dy[d],nx=x+w/4*3*dx[d];
        ok&=solve(u,v,ny,nx,w/4,(d+2)%4);
        d++;
    }
    return ok;
}

int N;

signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    if(solve(0,-1,0,0,1ll<<59,-1)){
        puts("YES");
        rep(i,N)printf("%lld %lld\n",ansx[i],ansy[i]);
    }
    else{
        puts("NO");
    }

}