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

int N,H;
double S0;
double calcS(double h){
    return S0*h*h/H/H;
}

signed main(){
    cin>>N>>H;
    S0=1.0*H/2;

    double S=S0;
    double h=H;

    double to=S0/N;
    vector<double>ans;
    rep(i,N-1){
        double tmp=(S-to)/S0*H*H;
        h=sqrt(tmp);
        S=calcS(h);
        ans.pb(h);
    }

    reverse(all(ans));
    for(auto d:ans)printf("%.20f\n",d);
    return 0;
}