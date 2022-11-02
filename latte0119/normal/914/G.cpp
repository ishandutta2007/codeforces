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

int N;
int A[1111111];
int cnt[1<<17];

int cntX[1<<17];
int cntY[1<<17];
const int mod=1000000007;

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

vint FWHT(vint P,bool inverse){
    for(int len=1;2*len<=P.size();len<<=1){
        for(int i=0;i<P.size();i+=2*len){
            for(int j=0;j<len;j++){
                int u=P[i+j];
                int v=P[i+len+j];
                P[i+j]=u+v;
                P[i+len+j]=u-v;
            }
        }
    }
    if(inverse){
        for(int i=0;i<P.size();i++)P[i]=P[i]/P.size();
    }

    return P;
}

void zeta(int f[1<<17]){
    rep(i,17)rep(b,1<<17)if(0==(b&(1<<i)))f[b]+=f[b|(1<<i)];
}
void me(int f[1<<17]){
    rep(i,17)rep(b,1<<17)if(b&(1<<i))f[b]-=f[b^(1<<i)];
}
int fib[1<<17];

signed main(){
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<1<<17;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;

    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        cnt[A[i]]++;
    }

    rep(i,1<<17){
        int sup=(1<<17)-1-i;
        int sub=sup;
        do{
            cntX[i|sub]+=cnt[i]*cnt[sub];
            sub=(sub-1)&sup;
        }while(sub!=sup);
    }
    rep(i,1<<17)cntX[i]%=mod;

    vint P(1<<17);
    rep(i,1<<17)P[i]=cnt[i];

    P=FWHT(P,false);
    rep(i,P.size())P[i]=P[i]*P[i];
    P=FWHT(P,true);

    rep(i,1<<17)cntY[i]=P[i]%mod;
    rep(i,1<<17){
        cnt[i]=cnt[i]*fib[i]%mod;
        cntX[i]=cntX[i]*fib[i]%mod;
        cntY[i]=cntY[i]*fib[i]%mod;
    }
    zeta(cnt);zeta(cntX);zeta(cntY);

    rep(i,1<<17){
        cnt[i]=(cnt[i]%mod+mod)%mod;
        cntX[i]=(cntX[i]%mod+mod)%mod;
        cntY[i]=(cntY[i]%mod+mod)%mod;
        cnt[i]=cnt[i]*cntX[i]%mod*cntY[i]%mod;
    }

    for(int i=0;i<1<<16;i++)swap(cnt[i],cnt[(1<<17)-1-i]);
    me(cnt);
    for(int i=0;i<1<<16;i++)swap(cnt[i],cnt[(1<<17)-1-i]);

    int ans=0;
    for(int i=1;i<1<<17;i<<=1){
        cnt[i]=(cnt[i]%mod+mod)%mod;
        ans=(ans+cnt[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}