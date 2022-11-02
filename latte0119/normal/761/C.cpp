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

int N,M;
string S[111];

signed main(){
    cin>>N>>M;
    rep(i,N)cin>>S[i];

    int ans=INT_MAX;
    rep(i,N)rep(j,N)rep(k,N){
        if(i==j||j==k||k==i)continue;
        int sum=0;

        int mi=111;
        rep(l,M)if(isdigit(S[i][l]))chmin(mi,min(l,M-l));
        sum+=mi;

        mi=111;
        rep(l,M)if(isalpha(S[j][l]))chmin(mi,min(l,M-l));
        sum+=mi;

        mi=111;
        rep(l,M)if(S[k][l]=='#'||S[k][l]=='&'||S[k][l]=='*')chmin(mi,min(l,M-l));
        sum+=mi;
        chmin(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}