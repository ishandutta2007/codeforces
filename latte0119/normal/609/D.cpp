#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,M,K,S;
int A[200000],B[200000];
int T[200000],C[200000];
signed main(){
    scanf("%lld%lld%lld%lld",&N,&M,&K,&S);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);
    rep(i,M)scanf("%lld%lld",&T[i],&C[i]);

    int lb=0,ub=N+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;

        int ma=INT_MAX,mb=INT_MAX;
        rep(i,mid){
            chmin(ma,A[i]);
            chmin(mb,B[i]);
        }

        vint ds(M);
        rep(i,M){
            if(T[i]==1)ds[i]=C[i]*ma;
            else ds[i]=C[i]*mb;
        }
        sort(all(ds));
        int tmp=accumulate(ds.begin(),ds.begin()+K,0ll);
        if(tmp>S)lb=mid;
        else ub=mid;
    }

    if(lb==N){
        puts("-1");
        return 0;
    }
    printf("%lld\n",ub);

    int ma=0,mb=0;
    rep(i,ub){
        if(A[ma]>A[i])ma=i;
        if(B[mb]>B[i])mb=i;
    }

    vpint ds(M);
    rep(i,M){
        if(T[i]==1)ds[i]=pint(C[i]*A[ma],i);
        else ds[i]=pint(C[i]*B[mb],i);
    }

    sort(all(ds));
    rep(i,K){
        int idx=ds[i].se;
        if(T[idx]==1)printf("%lld %lld\n",idx+1,ma+1);
        else printf("%lld %lld\n",idx+1,mb+1);
    }
    return 0;
}