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

int N,K;
int A[2222];

int dp[2222];

bool C(int x){

    for(int i=0;i<N;i++){
        dp[i]=i;
        for(int j=0;j<i;j++){
            int d=abs(A[i]-A[j]);
            if(x*(i-j-1)>=d-x)chmin(dp[i],dp[j]+i-j-1);
        }
    }

    for(int i=0;i<N;i++){
        if(dp[i]+N-1-i<=K)return true;
    }
    return false;
}

signed main(){
    cin>>N>>K;
    rep(i,N)cin>>A[i];


    int lb=-1,ub=1001001001001ll;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
}