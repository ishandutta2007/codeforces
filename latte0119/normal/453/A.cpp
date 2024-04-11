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
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;

double p;

double po(double p,int m){
    double res=1.0;
    while(m){
        if(m&1)res*=p;
        p=p*p;
        m>>=1;
    }
    return res;
}

signed main(){
    cin>>M>>N;
    p=1.0/M;

    double ans=0;
    for(int i=1;i<=M;i++){
        double q=po(p*i,N);
        q-=po(p*(i-1),N);
        ans+=q*i;
    }
    printf("%.20f\n",ans);
    return 0;
}