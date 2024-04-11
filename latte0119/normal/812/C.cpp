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

int N,S;
int A[111111];

int C(int x){
    vector<int>c(N);
    rep(i,N)c[i]=A[i]+x*(i+1);
    sort(all(c));
    return accumulate(c.begin(),c.begin()+x,0ll);
}

signed main(){
    cin>>N>>S;
    rep(i,N)cin>>A[i];

    int lb=0,ub=N+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid)<=S)lb=mid;
        else ub=mid;
    }
    cout<<lb<<" "<<C(lb)<<endl;
    return 0;
}