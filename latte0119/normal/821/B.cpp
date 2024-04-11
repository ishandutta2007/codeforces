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
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int M,B;

signed main(){
    cin>>M>>B;

    int ans=0;
    for(int i=0;i<=B*M;i++){
        int j=B-(i+M-1)/M;
        chmax(ans,(j+1)*(i*(i+1)/2)+(i+1)*(j*(j+1)/2));
    }
    cout<<ans<<endl;
    return 0;
}