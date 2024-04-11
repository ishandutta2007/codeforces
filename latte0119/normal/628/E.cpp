#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define each(i,c) for(auto i=(c).begin();i!=(c).end();i++)
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int H,W;
char fld[3010][3010];
int ans;

const int INF=1001001001;
int left_to[3010][3010],right_to[3010][3010];

int bit[3333+1];
void init_bit(){
    memset(bit,0,sizeof(bit));
}
void add(int k,int x){
    for(k++;k<=3333;k+=k&-k)bit[k]+=x;
}
int get(int k){
    int ret=0;
    for(k++;k;k-=k&-k)ret+=bit[k];
    return ret;
}

int z_to[3333];

void calc(int y,int x){
    vpint vec;
    for(int i=0;y<H&&x>=0;i++,y++,x--){
        if(fld[y][x]!='z'){
            z_to[i]=-INF;
            continue;
        }
        vec.pb(pint((left_to[y][x]+i)*2+1,i));
        z_to[i]=max(1ll,i?z_to[i-1]+1:-INF);
        vec.pb(pint((i+1)*2,min(z_to[i],right_to[y][x])));
    }


    sort(all(vec));
    reverse(all(vec));
    init_bit();

    rep(i,vec.size()){
        if(vec[i].fi&1){
            add(vec[i].se,1);
        }
        else{
            int j=vec[i].fi/2-1;
            ans+=get(j)-get(j-vec[i].se);

        }
    }
}

signed main(){
    scanf("%lld%lld",&H,&W);
    rep(i,H)scanf("%s",fld[i]);

    rep(i,H){
        rep(j,W){
            if(fld[i][j]!='z')left_to[i][j]=-INF;
            else left_to[i][j]=max(1ll,j?left_to[i][j-1]+1:-INF);
        }
        for(int j=W-1;j>=0;j--){
            if(fld[i][j]!='z')right_to[i][j]=-INF;
            else right_to[i][j]=max(1ll,j!=W-1?right_to[i][j+1]+1:-INF);
        }
    }

    rep(i,W)calc(0,i);
    reps(i,1,H)calc(i,W-1);
    printf("%lld\n",ans);


    return 0;
}