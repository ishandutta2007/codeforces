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

bitset<555555>dp;
int N,D;
signed main(){
    cin>>N>>D;
    dp[0]=1;
    rep(i,N){
        int a;cin>>a;
        dp|=dp<<a;
    }

    vint lis;
    rep(i,555555)if(dp[i])lis.pb(i);

    int cur=0;
    int cnt=0;
    while(true){
        int nex=cur;
        while(nex+1<lis.size()&&lis[nex+1]-lis[cur]<=D)nex++;
        if(cur==nex)break;
        cnt++;
        cur=nex;
    }

    cout<<lis[cur]<<" "<<cnt<<endl;
    return 0;
}