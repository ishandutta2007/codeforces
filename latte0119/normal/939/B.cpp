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
int A[111111];

signed main(){
    cin>>N>>K;
    rep(i,K)cin>>A[i];

    int ma=0;
    rep(i,K)if(N/A[ma]*A[ma]<N/A[i]*A[i])ma=i;

    cout<<ma+1<<" "<<N/A[ma]<<endl;
    return 0;
}