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

int N,K;
int C[500000];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&C[i]);

    int sum=0;
    rep(i,N)sum+=C[i];
    int to;
    if(sum%N==0)to=sum/N;
    else to=sum/N+1;

    int lb=to-1,ub=1000000000;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        int diff=0;
        rep(i,N)diff+=max(0ll,C[i]-mid);
        if(diff<=K)ub=mid;
        else lb=mid;
    }

    int up=ub;

    to=sum/N;
    lb=1;
    ub=to+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        int diff=0;
        rep(i,N)diff+=max(0ll,mid-C[i]);
        if(diff<=K)lb=mid;
        else ub=mid;
    }
    int dw=lb;

    printf("%lld\n",up-dw);
    return 0;
}