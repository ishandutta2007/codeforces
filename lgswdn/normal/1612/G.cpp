#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e6+9,mod=1e9+7,BASE=1e6;
int m,c[N],a[N],d[N],s[N],fac[N],ans1,ans2=1;

signed main() {
    m=read();
    rep(i,1,m) c[i]=read();
    fac[0]=1; rep(i,1,m) fac[i]=fac[i-1]*i%mod;
    rep(i,1,m) d[BASE-c[i]+1]++, d[BASE+c[i]+1]--;
    int tot=1;
    rep(i,1,2*BASE) {
        if(i>1) s[i]=s[i-2]+d[i]; else s[i]=d[i];
        ans1=(ans1+((tot+tot+s[i]-1)*s[i]/2)%mod*(i-BASE))%mod, tot+=s[i];
        ans2=ans2*fac[s[i]]%mod;
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;  
}