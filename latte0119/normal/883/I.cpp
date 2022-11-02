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

int dp[333333];

bool C(int x,vint &a,int k){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int cur=0;
    int sum=0;

    rep(i,a.size()){
        while(a[i]-a[cur]>x){
            sum-=dp[cur];
            cur++;
        }
        if(i-k+1>=0)sum+=dp[i-k+1];
        if(i-cur+1>=k)dp[i+1]=(sum>0);
    }
    return dp[a.size()];
}

signed main(){
    int N,K;cin>>N>>K;
    vint A(N);rep(i,N)cin>>A[i];
    sort(all(A));
    int lb=-1,ub=INT_MAX;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid,A,K))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}