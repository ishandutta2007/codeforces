#include <bits/stdc++.h>
using namespace std;
// adjust: ... among n players ...
// ans=ans'*(n-1)/n
// something like ZJOI2019 Day2T2
// m=sum a_i
// e.g.f: (not first)
// sum(((e^(x/m)-1)/n)^(m-a_i))*((e^(x/m)-1)/n+1)^a_i))
// sum((e^(x/m)-1)^(m-a_i)*(e^(x/m)+(n-1))^a_i)/(n^m) (f/n^m)
// e.g.f remain:
// ((n-1)*(e^(x/m)-1)^m+(e^(x/m)+(n-1))^m)/(n^m) (g/n^m)
// e^(kx) <=> 1/(1-kx) convert to g.f
// ans=(f/g)'|(x=1)=((gf'-fg')/g^2)|(x=1)
// g=n/(1-x)+G f=n/(1-x)+F
// ((n/(1-x)^2+A)*(n/(1-x)+G)-(n/(1-x)^2+B)*(n/(1-x)+F))/(n^2/(1-x)^2)
// (G-F)/n *(n-1)/n
// ----------------
// calc G-F:
// sum(f_i*x^i)=sum((x-1)^(m-a_i)*(x+(n-1))^a_i)
// sum(g_i*x^i)=(n-1)*(x-1)^m+(x+(n-1))^m
// G-F=sum((g_i-f_i)/(1-i/m))=m*sum((g_i-f_i)/(m-i))
// re-define: sum(f_i*x^i)=sum((1-x)^(m-a_i)*(1+(n-1)x)^a_i)
//            sum(g_i*x^i)=(n-1)*(1-x)^m+(1+(n-1)x)^m
// G-F=m*sum((g_i-f_i)/i)=m*integral(((n-1)*(1-x)^m+(1+(n-1)x)^m-sum((1-x)^(m-a_i)*(1+(n-1)x)^a_i))/x,x=0 to 1)
// integral(((n-1)*(1-x)^m+(1+(n-1)x)^m)/x,x=0 to 1)=integral(((n-1)x^m+(1+(n-1)(1-x))^m-n)/(1-x),x=0 to 1) expand
// integral(sum((1-x)^(m-a_i)*(1+(n-1)x)^a_i)/x,x=0 to 1)=integral(sum(x^(m-a_i)*(1+(n-1)(1-x))^a_i)/(1-x),x=0 to 1) expand (sum a_i<=2e)
// (ignore ln0-ln1)
// 1+(n-1)(1-x)=n-(n-1)x
// integral((x^k-1)/(1-x),x=0 to 1)=-integral(x^0+...+x^(k-1),x=0 to 1)=-H_k
typedef long long ll;
const int kcz=998244353;
const int maxn=100005;
const int maxm=300005;
int n,m/*,logm*/,a[maxn],invn1; // rev[maxm<<2];
ll inv[maxm],fac[maxm],invfac[maxm],pow_n1[maxm],H[maxm];
// ll G[2][24],f[maxm<<2],g[maxm<<2];
// #define add(x,y) (((x)+=(y))>=kcz)?x-=kcz:0; }
// inline ll add_(ll x,ll y) { return ((x+=y)>=kcz)?x-kcz:x; }
inline ll qpow(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) (res*=a)%=kcz;
        if(k>>=1) (a*=a)%=kcz;
    }
    return res;
}
inline ll C(int n,int m) { return fac[n]*invfac[m]%kcz*invfac[n-m]%kcz; }
// inline void init()
// {
//     int i;
//     G[1][23]=qpow(G[0][23]=qpow(3,kcz>>23),kcz-2);
//     for(i=22;i>=0;i--)
//         G[0][i]=G[0][i+1]*G[0][i+1]%kcz,G[1][i]=G[1][i+1]*G[1][i+1]%kcz;
// }
// inline void calcrev(int logn)
// {
//     int i;
//     for(rev[0]=0,i=1;i<(1<<logn);i++)
//         rev[i]=(rev[i>>1]>>1)|((i&1)<<(logn-1));
// }
// inline void DFT(ll *a,int logn,int flag)
// {
//     int i,j,mid,k;
//     ll t0,t1,temp;
//     for(i=0;i<(1<<logn);i++)
//         if(rev[i]<i)
//             swap(a[rev[i]],a[i]);
//     for(i=1;i<=logn;i++)
//         for(j=0,mid=1<<(i-1);j<(1<<logn);j+=1<<i)
//             for(k=0,temp=1;k<mid;k++,(temp*=G[flag][i])%=kcz)
//             {
//                 t0=a[j|k],t1=a[j|k|mid]*temp%kcz;
//                 a[j|k]=add_(t0,t1),a[j|k|mid]=add_(t0,kcz-t1);
//             }
// }
int main()
{
    int i,j;
    ll ans,temp;
    scanf("%d",&n);
    for(m=0,i=0;i<n;i++) scanf("%d",&a[i]),m+=a[i];
    inv[1]=fac[0]=fac[1]=invfac[0]=invfac[1]=1,pow_n1[0]=1,pow_n1[1]=kcz-n+1,H[0]=0,H[1]=1;
    for(/*init(),*/i=2;i<=m;i++)
    {
        inv[i]=kcz-(kcz/i)*inv[kcz%i]%kcz;
        fac[i]=fac[i-1]*i%kcz;
        invfac[i]=invfac[i-1]*inv[i]%kcz;
        pow_n1[i]=pow_n1[i-1]*(kcz-n+1)%kcz;
        H[i]=(H[i-1]+inv[i])%kcz;
    }

    // // calc F: sum(x^(m-a_i)*(x+n)^a_i) (sum(a_i)=m<=3e5)
    // for(i=0;i<=m;i++) f[i]=0;
    // for(i=0;i<n;i++)
    //     for(j=0,temp=1;j<=a[i];j++,(temp*=n)%=kcz)
    //         (f[m-j]+=temp*C(a[i],j))%=kcz;
    // // real f(x)=F(x-1)=sum(a_i*(x-1)^i)=sum(a_i*sum(x^j*(-1)^(i-j)*C(i,j)))
    // //          =sum(x^j/j!*sum(a_i*i!*(-1)^(i-j)/(i-j)!))
    // for(logm=0;(1<<logm)<=(m<<1);logm++);
    // calcrev(logm);
    // for(i=0;i<=m;i++) (f[i]*=fac[i])%=kcz,g[i]=0;
    // for(i=m+1;i<(1<<logm);i++) f[i]=g[i]=0;
    // for(i=0;i<=m;i++) g[i?(1<<logm)-i:0]=(i&1)?kcz-invfac[i]:invfac[i];
    // DFT(f,logm,0),DFT(g,logm,0);
    // for(i=0;i<(1<<logm);i++) (f[i]*=g[i])%=kcz;
    // DFT(f,logm,1);
    // // for(i=0,temp=qpow(1<<logm,kcz-2);i<(1<<logm);i++) printf("%lld ",(f[i]*temp%kcz<kcz-f[i]*temp%kcz)?f[i]*temp%kcz:(f[i]*temp%kcz-kcz)); printf("\n");
    // for(temp=qpow(1<<logm,kcz-2),i=0;i<=m;i++) (f[i]*=temp*invfac[i]%kcz)%=kcz;
    // // g: (n-1)*(x-1)^m+(x+(n-1))^m)
    // for(i=0,temp=1;i<=m;i++,(temp*=n-1)%=kcz) g[m-i]=(((i&1)?(kcz-n+1):(n-1))+temp)*C(m,i)%kcz;
    // // for(i=0;i<=m;i++) printf("%lld ",(g[i]<kcz-g[i])?g[i]:(g[i]-kcz)); printf("\n");
    // // for(i=0;i<=m;i++) printf("%lld ",(f[i]<kcz-f[i])?f[i]:(f[i]-kcz)); printf("\n");
    // for(temp=0,i=0;i<m;i++) (temp+=m*inv[m-i]%kcz*(g[i]+kcz-f[i]))%=kcz;
    // printf("%lld\n",temp*qpow(n,kcz-3)%kcz*(n-1)%kcz);

    invn1=qpow(n-1,kcz-2),ans=0;
    // F integral(sum(x^(m-a_i)*(n-(n-1)x)^a_i/(1-x)),x=0 to 1)
    for(i=0;i<n;i++)
        for(j=0,temp=pow_n1[a[i]];j<=a[i];j++,(temp*=(kcz-n)*(ll)invn1%kcz)%=kcz)
            (ans+=H[m-j]*C(a[i],j)%kcz*temp)%=kcz;
    // G
    for(j=0,temp=kcz-pow_n1[m];j<=m;j++,(temp*=(kcz-n)*(ll)invn1%kcz)%=kcz)
        (ans+=H[m-j]*C(m,j)%kcz*temp)%=kcz;
    (ans+=H[m]*(kcz-n+1))%=kcz;
    printf("%lld\n",ans*qpow(n,kcz-3)%kcz*(n-1)%kcz*m%kcz);
    return 0;
}