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

int N,M;
int G[22];

int dp[1<<22];
int pre1[1<<22],pre2[1<<22];
signed main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a]|=1<<b;
        G[b]|=1<<a;
    }

    fill_n(dp,1<<22,INT_MAX);
    dp[0]=0;
    for(int i=0;i<1<<N;i++){
        for(int j=0;j<N;j++){
            if(i>>j&1){
                int to=i|G[j];
                if(dp[to]<=dp[i]+1)continue;
                dp[to]=dp[i]+1;
                pre1[to]=i;
                pre2[to]=j;
            }
            else{
                if((i&G[j])!=i)continue;
                int to=i|(1<<j);
                if(dp[to]<=dp[i])continue;
                dp[to]=dp[i];
                pre1[to]=i;
                pre2[to]=-1;
            }
        }
    }

    int b=(1<<N)-1;
    vint ans;
    while(b){
        if(pre2[b]!=-1)ans.pb(pre2[b]);
        b=pre1[b];
    }

    reverse(all(ans));
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        if(i)cout<<" ";
        cout<<ans[i]+1;
    }cout<<endl;
    return 0;
}