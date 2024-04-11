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
    int R,D;
    cin>>R>>D;
    D=R-D;
    int N;cin>>N;
    int cnt=0;
    rep(i,N){
        int x,y,r;
        cin>>x>>y>>r;

        int s=x*x+y*y;
        if(D&&s<(D+r)*(D+r))continue;
        if(r>R)continue;
        if(s>(R-r)*(R-r))continue;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}