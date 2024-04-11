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

int N,Q;
int C;

int sum[11][222][222];

signed main(){
    cin>>N>>Q>>C;
    rep(i,N){
        int x,y,s;
        cin>>x>>y>>s;
        sum[s][x][y]++;
    }

    rep(k,C+1){
        rep(i,111)rep(j,111)sum[k][i+1][j+1]+=sum[k][i+1][j]+sum[k][i][j+1]-sum[k][i][j];
    }

    while(Q--){
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        x1--;y1--;
        int ans=0;
        rep(i,C+1){
            int tmp=sum[i][x2][y2]-sum[i][x1][y2]-sum[i][x2][y1]+sum[i][x1][y1];
            ans+=(i+t)%(C+1)*tmp;
        }

        cout<<ans<<endl;
    }
    return 0;
}