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

int dy[]={-1,-1,-1,0,1,1,1,0};
int dx[]={-1,0,1,1,1,0,-1,-1};

bool vis[500][500];

int N;
bool change[200];

signed main(){
    cin>>N;
    int T=0;
    rep(i,N){

        int t;cin>>t;
        T+=t;
        change[T]=true;
    }

    vector<tuple<int,int,int>>vec;
    vec.pb(make_tuple(1,250,250));
    for(int latte=1;latte<=T;latte++){
        vector<tuple<int,int,int>>nex;
        rep(i,vec.size()){
            int d,y,x;
            tie(d,y,x)=vec[i];
            vis[y][x]=true;
            if(change[latte]){
                for(int dd=-1;dd<=1;dd+=2){
                    int nd=(d+dd+8)%8;
                    int ny=y+dy[nd],nx=x+dx[nd];
                    nex.pb(make_tuple(nd,ny,nx));
                }
            }
            else{
                int ny=y+dy[d],nx=x+dx[d];
                nex.pb(make_tuple(d,ny,nx));
            }
        }
        sort(all(nex));
        nex.erase((unique(all(nex))),nex.end());
        vec=nex;
    }

    int ans=0;
    rep(i,500)rep(j,500)ans+=vis[i][j];
    cout<<ans<<endl;
    return 0;
}