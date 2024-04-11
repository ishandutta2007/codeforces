#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const double EPS=1e-8;
int n,l,v1,v2,k;

bool C(double aim){
    double t=0,x=0;
    int nn=n;
    while(nn>0){
        if((l-x)/v1+t<aim+EPS)return true;
        if((l-x)/v2+t>aim+EPS)return false;
        nn=max(0ll,nn-k);
        double tt=(aim-t-(l-x)/v1)/(1-(double)v2/v1);
        t+=tt;
        x+=tt*v1;

        if(nn==0)return true;
        tt=(tt*v2-tt*v1)/(v1+v2);
        t+=tt;
        x+=tt*v1;
    }
}

signed main(){
    cin>>n>>l>>v1>>v2>>k;

    double lb=0,ub=1e12;
    rep(i,1000){
        double mid=(ub+lb)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }
    printf("%.20f\n",ub);
    return 0;
}