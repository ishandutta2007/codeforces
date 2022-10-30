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

signed main(){
    int N;
    int x0,y0;
    scanf("%lld%lld%lld",&N,&x0,&y0);
    vint X(N),Y(N);
    vector<char>M(N);
    rep(i,N)scanf(" %c%lld%lld",&M[i],&X[i],&Y[i]);

    for(int dy=-1;dy<=1;dy++){
        for(int dx=-1;dx<=1;dx++){
            if(!dy&&!dx)continue;
            int arcmi=-1;
            int mi=LLONG_MAX;
            rep(i,N){
                int y=Y[i]-y0,x=X[i]-x0;
                int t=max(abs(x),abs(y));
                if(dy*t!=y||dx*t!=x)continue;
                if(mi>t){
                    mi=t;
                    arcmi=i;
                }
            }
            if(arcmi==-1)continue;
            if(dy==0||dx==0){
                if(M[arcmi]=='B')continue;
                puts("YES");
                return 0;
            }
            else{
                if(M[arcmi]=='R')continue;
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}