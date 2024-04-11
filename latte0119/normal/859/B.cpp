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

signed main(){
    int N;cin>>N;
    int ans=INT_MAX;
    for(int i=1;i<=4000;i++){
        for(int j=1;j<=4000;j++){
            if(i*j>=N)chmin(ans,(i+j)*2);
        }
    }
    cout<<ans<<endl;
    return 0;
}