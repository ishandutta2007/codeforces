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

int H,W,K;
bool a[5000],b[5000];
int fld[5000][5000];
int t[100000],r[100000],c[100000];
signed main(){
    scanf("%lld%lld%lld",&H,&W,&K);
    rep(i,K)scanf("%lld%lld%lld",&t[i],&r[i],&c[i]),r[i]--;

    for(int i=K-1;i>=0;i--){
        if(t[i]==1){
            if(a[r[i]])continue;
            a[r[i]]=true;
            rep(j,W)if(fld[r[i]][j]==0)fld[r[i]][j]=c[i];
        }
        else{
            if(b[r[i]])continue;
            b[r[i]]=true;
            rep(j,H)if(fld[j][r[i]]==0)fld[j][r[i]]=c[i];
        }
    }

    rep(i,H){
        rep(j,W)printf("%lld ",fld[i][j]);
        puts("");
    }
    return 0;
}