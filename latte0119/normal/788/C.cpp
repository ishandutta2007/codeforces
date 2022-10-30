#include<bits/stdc++.h>
using namespace std;

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


const int INF=1001001001;
const int lim=500*500;
int N,K;
bool ex[1111];

vint calc(vint A){
    vint res(lim+1,INF);
    res[0]=0;

    for(int i=1;i<=lim;i++){
        for(int j=0;j<A.size();j++)if(i>=A[j])chmin(res[i],res[i-A[j]]+1);
    }
    return res;
}

int main(){
    scanf("%d%d",&N,&K);
    int a;
    rep(i,K){
        scanf("%d",&a);
        ex[a]=true;
    }


    if(ex[N]){
        puts("1");
        return 0;
    }

    vint A,B;
    for(int i=0;i<N;i++)if(ex[i])A.pb(N-i);
    for(int i=N+1;i<=1000;i++)if(ex[i])B.pb(i-N);

    if(A.size()==0||B.size()==0){
        puts("-1");
        return 0;
    }
    
    vint X=calc(A);
    vint Y=calc(B);

    int ans=INF;
    for(int i=1;i<=lim;i++)chmin(ans,X[i]+Y[i]);
    
    assert(ans!=INF);
    printf("%d\n",ans);
    return 0;
}