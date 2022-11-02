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

bool sq[1111111];

signed main(){
    int N;
    scanf("%lld",&N);
    vint A(N);rep(i,N)scanf("%lld",&A[i]);
    sort(all(A));

    for(int i=0;i<=1000;i++)sq[i*i]=1;

    for(int i=N-1;i>=0;i--){
        if(A[i]<0||!sq[A[i]]){
            cout<<A[i]<<endl;
            return 0;
        }
    }
    return 0;
}