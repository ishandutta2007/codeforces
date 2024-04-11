#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2525; 

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int id[N],rid[N],cnt,a[N],tot;
long long l,r,f[29][N][55][2];

long long dfs(int pos,int md,int lcm,bool lim) {
    if(pos==0) {
        return (md%rid[lcm]==0);
    }
    if(f[pos][md][lcm][lim] != -1) return f[pos][md][lcm][lim];
    long long ret = 0 ;
    ret+=dfs(pos-1,md*10%2520,lcm,a[pos]==0&&lim);
    rep(i,1,lim?a[pos]:9) {
        ret+=dfs(pos-1,(md*10+i)%2520,id[rid[lcm]*i/__gcd(rid[lcm],i)],i==a[pos]&&lim);
    }
    if (!lim) f[pos][md][lcm][lim] = ret ;
    return ret;
}

long long solve(long long x) {
    tot=0; 
    while(x) {
        a[++tot]=x%10;
        x/=10;
    }
    return dfs(tot,0,1,1);
}

signed main() {
    int T=read();
    memset(f,-1,sizeof(f));
    rep(i,1,2520) if(2520%i==0) id[i]=++cnt,rid[cnt]=i;
    while(T--) {
        l=read(), r=read();
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}