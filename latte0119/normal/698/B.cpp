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
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


struct UF{
    vint par;
    void init(int n){
        par.resize(n);
        rep(i,n)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        par[find(y)]=find(x);
    }
};

int N;
int P[200000];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&P[i]),P[i]--;
    UF uf;
    uf.init(N);
    int r=-1;
    rep(i,N)if(P[i]==i)r=i;
    int cnt=0;
    rep(i,N){
        int j=P[i];
        if(uf.find(i)!=uf.find(j)){
            uf.unite(i,j);
        }
        else{
            if(r==-1){
                cnt+=P[i]!=i;
                P[i]=i;
                r=i;
            }
            else{
                cnt+=P[i]!=r;
                P[i]=r;
                uf.unite(i,r);
            }
        }
    }
    printf("%lld\n",cnt);
    rep(i,N)printf("%lld ",P[i]+1);
    puts("");
    return 0;
}