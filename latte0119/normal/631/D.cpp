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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N,M;

int l[200000];
char c[200000];

int ll[200000];
char cc[200000];

void press(int &N,int *l,char *c){
    int n=1;
    for(int i=1;i<N;i++){
        if(c[n-1]==c[i]){
            l[n-1]+=l[i];
        }
        else{
            l[n]=l[i];
            c[n]=c[i];
            n++;
        }
    }
    N=n;
}

typedef unsigned long long ull;
const ull p=1000000007,q=8931919;
ull power[222222];

ull x[222222],y[222222];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld-%c",&l[i],&c[i]);
    rep(i,M)scanf("%lld-%c",&ll[i],&cc[i]);

    press(N,l,c);
    press(M,ll,cc);

    int ans=0;
    if(M==1){
        rep(i,N)if(c[i]==cc[0])ans+=max(0ll,l[i]-ll[0]+1);
        printf("%lld\n",ans);
        return 0;
    }
    if(M==2){
        rep(i,N-1)if(c[i]==cc[0]&&c[i+1]==cc[1]&&l[i]>=ll[0]&&l[i+1]>=ll[1])ans++;
        printf("%lld\n",ans);
        return 0;
    }

    rep(i,N)x[i]=l[i]+c[i]*q;
    rep(i,M)y[i]=ll[i]+cc[i]*q;

    power[0]=1;
    for(int i=1;i<=200000;i++)power[i]=power[i-1]*p;

    if(N<M){
        puts("0");
        return 0;
    }

    ull hh=0;
    for(int i=1;i<M-1;i++){
        hh=hh*p+y[i];
    }

    ull h=0;
    for(int i=1;i<N-1;i++){
        h=h*p+x[i];
        if(i<M-2)continue;
        if(h==hh){
            if(l[i-M+2]>=ll[0]&&c[i-M+2]==cc[0]&&l[i+1]>=ll[M-1]&&c[i+1]==cc[M-1])ans++;
        }
        h-=x[i-M+3]*power[M-3];
    }

    printf("%lld\n",ans);
    return 0;
}