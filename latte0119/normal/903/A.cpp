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

bool ok[11111];

signed main(){
    rep(i,111)rep(j,111)ok[i*3+7*j]=true;
    int n;cin>>n;
    while(n--){
        int a;cin>>a;
        if(ok[a])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}