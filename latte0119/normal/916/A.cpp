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

int X;
int T;

signed main(){
    cin>>X;
    int a,b;cin>>a>>b;
    T=a*60+b;

    int ans=INT_MAX;
    rep(i,60*24){
        a=i/60;
        b=i%60;
        if(a%10!=7&&b%10!=7)continue;
        int d=T-i;
        if(d<0)d+=60*24;
        if(d%X)continue;
        chmin(ans,d/X);
    }
    cout<<ans<<endl;
    return 0;
}