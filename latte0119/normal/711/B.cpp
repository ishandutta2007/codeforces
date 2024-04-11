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
    cin>>N;
    vector<vint>A(N,vint(N));
    rep(i,N)rep(j,N)cin>>A[i][j];

    int S=1;
    int y,x;
    rep(i,N){
        bool ok=true;
        rep(j,N){
            if(A[i][j]==0){
                y=i;
                x=j;
                ok=false;
                break;
            }
        }
        if(ok){
            S=0;
            rep(j,N)S+=A[i][j];
        }
    }

    A[y][x]=S-accumulate(all(A[y]),0ll);
    bool ok=true;
        if(A[y][x]<=0)ok=false;
    rep(i,N){
        int sum=0;
        rep(j,N)sum+=A[i][j];
        if(sum!=S)ok=false;
    }
    rep(j,N){
        int sum=0;
        rep(i,N)sum+=A[i][j];
        if(sum!=S)ok=false;
    }
    int sum=0;
    rep(i,N){
        sum+=A[i][i];
    }
    if(sum!=S)ok=false;
    sum=0;
    rep(i,N){
        sum+=A[i][N-1-i];
    }
    if(sum!=S)ok=false;

    if(ok)cout<<A[y][x]<<endl;
    else cout<<-1<<endl;
    return 0;
}