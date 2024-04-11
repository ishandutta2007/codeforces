#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

using D=long double;

int N,X;
int C[111];

D table[111][111];
D dp[101][10001];

signed main(){
    table[0][0]=1.0;
    for(int i=1;i<111;i++){
        table[i][0]=table[i][i]=1.0;
        for(int j=1;j<i;j++)table[i][j]=table[i-1][j-1]+table[i-1][j];
    }

    scanf("%lld%lld",&N,&X);
    rep(i,N)scanf("%lld",&C[i]);
    sort(C,C+N);
    dp[0][0]=1;
    int lim=0;
    rep(i,N){
        for(int j=i;j>=0;j--){
            for(int k=lim;k>=0;k--){
                dp[j+1][k+C[i]]+=dp[j][k];
            }
        }
        lim+=C[i];
    }

    D ans=0.0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=lim;j++){
            D tmp=dp[i][j]/table[N][i];
            if((i+N)*X<=2*j){
                tmp*=0.5*(i+N)*X/i;
            }
            else{
                tmp*=1.0*j/i;
            }
            ans+=tmp;
        }
    }
    printf("%.20Lf\n",ans);
    return 0;
}