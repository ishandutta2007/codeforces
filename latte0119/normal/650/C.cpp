#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
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

int H,W;
vector<vint>A;

vector<vint>B;

int row[1111111],col[1111111];
vpint lis[1111111];
vint xlis[1111111],ylis[1111111];
int uf_n,par[1111111],val[1111111];
void init(int n,vint &v){
    uf_n=n;
    rep(i,uf_n)par[i]=i,val[i]=v[i];
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    chmax(val[x],val[y]);
    par[y]=x;
}

signed main(){
    scanf("%lld%lld",&H,&W);
    A.resize(H,vint(W));
    B.resize(H,vint(W));
    vint press;
    rep(i,H)rep(j,W)scanf("%lld",&A[i][j]);
    rep(i,H)rep(j,W)press.pb(A[i][j]);
    sort(all(press));press.erase(unique(all(press)),press.end());
    rep(i,H)rep(j,W)A[i][j]=lower_bound(all(press),A[i][j])-press.begin();

    rep(i,H)rep(j,W)lis[A[i][j]].pb(pint(i,j));

    rep(t,press.size()){
        vpint &vec=lis[t];
        vint v(vec.size());
        rep(i,vec.size()){
            ylis[vec[i].fi].pb(i);
            xlis[vec[i].se].pb(i);
            chmax(v[i],row[vec[i].fi]);
            chmax(v[i],col[vec[i].se]);
            v[i]++;
        }
        init(vec.size(),v);
        rep(i,vec.size()){
            for(int j=0;j+1<ylis[vec[i].fi].size();j++){
                unite(ylis[vec[i].fi][j],ylis[vec[i].fi][j+1]);
            }
            for(int j=0;j+1<xlis[vec[i].se].size();j++){
                unite(xlis[vec[i].se][j],xlis[vec[i].se][j+1]);
            }
            ylis[vec[i].fi].clear();
            xlis[vec[i].se].clear();
        }
        rep(i,vec.size()){
            B[vec[i].fi][vec[i].se]=val[find(i)];
            chmax(row[vec[i].fi],B[vec[i].fi][vec[i].se]);
            chmax(col[vec[i].se],B[vec[i].fi][vec[i].se]);
        }
    }

    rep(i,H){
        rep(j,W){
            if(j)printf(" ");
            printf("%lld",B[i][j]);
        }puts("");
    }
    return 0;
}