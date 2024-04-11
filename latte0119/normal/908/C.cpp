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

int N,R;
int X[1111];

long double y[1111];

signed main(){
    cin>>N>>R;
    rep(i,N)cin>>X[i];

    rep(i,N){
        vector<long double>lis;
        rep(j,i){
            int d=abs(X[i]-X[j]);
            if(d>2*R)continue;
            int tmp=4*R*R-d*d;
            lis.pb(sqrt(1.0*tmp)+y[j]);
        }
        if(lis.size()==0)y[i]=R;
        else y[i]=*max_element(all(lis));
    }

    rep(i,N){
        if(i)printf(" ");
        printf("%.20Lf",y[i]);
    }puts("");
    return 0;
}