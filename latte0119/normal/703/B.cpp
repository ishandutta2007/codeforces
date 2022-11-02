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

int N;
int K;
int C[100000];
bool f[100000];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&C[i]);
    int sum2=0;
    rep(i,K){
        int a;
        scanf("%lld",&a);
        a--;
        f[a]=true;
        sum2+=C[a];
    }
    int sum=accumulate(C,C+N,0ll);
    int ans=0;
    rep(i,N){
        if(f[i]){
            ans+=C[i]*(sum-C[i]);
        }
        else{
            int t=(i-1+N)%N;
            if(!f[t])ans+=C[i]*C[t];
            t=(i+1)%N;
            if(!f[t])ans+=C[i]*C[t];
            ans+=C[i]*sum2;
        }
    }

    cout<<ans/2<<endl;
    return 0;
}