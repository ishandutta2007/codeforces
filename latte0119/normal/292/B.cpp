#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
vint G[100000];

signed main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    if(M==N-1){
        int v=-1;
        rep(i,N){
            if(G[i].size()==M){
                cout<<"star topology"<<endl;
                return 0;
            }
            if(G[i].size()==1)v=i;
        }

        if(v>=0){
            int u=-1;
            bool ok=true;
            rep(i,N-1){
                if(G[v].size()>2){
                    ok=false;
                    break;
                }
                [&](){
                    for(auto to:G[v]){
                        if(to==u)continue;
                        u=v;
                        v=to;
                        return;
                    }
                    ok=false;
                }();
            }
            if(ok){
                cout<<"bus topology"<<endl;
                return 0;
            }
        }
    }
    if(N==M){
        int v=0,u=-1;
        bool ok=true;
        rep(i,N-1){
            if(G[v].size()!=2){
                ok=false;
                break;
            }
            [&](){
                for(auto to:G[v]){
                    if(to==u)continue;
                    u=v;
                    v=to;
                    return;
                }
                ok=false;
            }();
        }
        if(ok){
            cout<<"ring topology"<<endl;
            return 0;
        }
    }
    cout<<"unknown topology"<<endl;
    return 0;
}