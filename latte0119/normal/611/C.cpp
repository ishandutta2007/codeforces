#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int H,W;
int fld[500][500];

int a[501][501],b[501][501];

signed main(){
    scanf("%d%d",&H,&W);
    rep(i,H)rep(j,W){
        char c;scanf(" %c",&c);
        if(c=='#')fld[i][j]=1;
    }

    rep(i,H)rep(j,W){
        if(fld[i][j])continue;
        if(i&&!fld[i-1][j])a[i+1][j+1]=1;
        if(j&&!fld[i][j-1])b[i+1][j+1]=1;
    }


    rep(i,H)rep(j,W){
        a[i+1][j+1]+=a[i][j+1]+a[i+1][j]-a[i][j];
        b[i+1][j+1]+=b[i][j+1]+b[i+1][j]-b[i][j];
    }

    int Q;scanf("%d",&Q);
    while(Q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        int v1=a[y2][x2]-a[y1][x2]-a[y2][x1-1]+a[y1][x1-1];
        int v2=b[y2][x2]-b[y2][x1]-b[y1-1][x2]+b[y1-1][x1];
        printf("%d\n",v1+v2);
    }
    return 0;
}