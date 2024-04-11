#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const double EPS=1e-6;
const double INF=1e18;

struct CHT{
    typedef pair<double,double>L;
    deque<L>ls;

    bool check(L &l1,L &l2,L &l3){
        return (l2.fi-l3.fi)*(l1.se-l2.se)<(l1.fi-l2.fi)*(l2.se-l3.se)+EPS;
    }

    void add(double a,double b){
        L l(a,b);
        while(ls.size()>=2&&check(ls[ls.size()-2],ls[ls.size()-1],l))ls.pop_back();
        ls.push_back(l);
    }

    double query(double x){
        while(ls.size()>1&&ls[0].fi*x+ls[0].se+EPS>ls[1].fi*x+ls[1].se)ls.pop_front();
        return ls[0].fi*x+ls[0].se;
    }
};

const int SIZE=200000;
int N,K;
int A[SIZE+1];

double S[SIZE+1],T[SIZE+1];
int SS[SIZE+1];
double dp[51][SIZE+1];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N){
        scanf("%lld",&A[i+1]);
        SS[i+1]=SS[i]+A[i+1];
        S[i+1]=S[i]+1.0*SS[i+1]/A[i+1];
        T[i+1]=T[i]+1.0/A[i+1];
    }

    fill_n(*dp,51*(SIZE+1),INF);
    dp[0][0]=0;
    rep(k,K){
        CHT cht;
        cht.add(0,dp[k][0]);
        rep(i,N){
            dp[k+1][i+1]=S[i+1]+cht.query(T[i+1]);
            cht.add(-SS[i+1],dp[k][i+1]-S[i+1]+T[i+1]*SS[i+1]);
        }
    }

    printf("%.20f\n",dp[K][N]);
    return 0;
}