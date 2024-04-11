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

int H,W,Q;
int T[10000],A[10000],B[10000],C[10000];
int ans[100][100];

signed main(){
    scanf("%lld%lld%lld",&H,&W,&Q);
    rep(i,Q){
        scanf("%lld",&T[i]);
        if(T[i]<=2)scanf("%lld",&A[i]),A[i]--;
        else scanf("%lld%lld%lld",&A[i],&B[i],&C[i]),A[i]--,B[i]--;
    }

    rep(i,Q){
        if(T[i]!=3)continue;
        int y=A[i],x=B[i];
        for(int j=i-1;j>=0;j--){
            if(T[j]==1&&A[j]==y){
                x++;
                if(x==W)x=0;
            }
            else if(T[j]==2&&A[j]==x){
                y++;
                if(y==H)y=0;
            }
        }
        ans[y][x]=C[i];
    }

    rep(i,H){
        rep(j,W)printf("%lld ",ans[i][j]);
        puts("");
    }
    return 0;
}