#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int N;
int A[55][55];

signed main(){
    cin>>N;
    rep(i,N)rep(j,N)cin>>A[i][j];

    rep(i,N)rep(j,N){
        if(A[i][j]==1)continue;
        bool ok=false;
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                if(A[i][x]+A[y][j]==A[i][j])ok=true;
            }
        }
        if(!ok){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}