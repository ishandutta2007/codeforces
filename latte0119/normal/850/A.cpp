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

typedef vector<int>vec;


int N;
vec A[1111];

signed main(){
    cin>>N;
    rep(i,N){
        A[i].resize(5);
        rep(j,5)cin>>A[i][j];
    }

    vint ans;

    rep(i,N){
        vector<vec>v;
        rep(j,N){
            if(i==j)continue;
            vec x(5);
            rep(k,5)x[k]=A[j][k]-A[i][k];
            v.pb(x);
            if(v.size()>40)break;
        }

        if(v.size()>40)continue;

        bool flag=true;
        rep(k,v.size())rep(l,v.size()){
            if(k==l)continue;
            int c=0;
            rep(m,5)c+=v[k][m]*v[l][m];
            if(c>0)flag=false;
        }
        if(flag)ans.pb(i);
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]+1<<endl;


    return 0;
}