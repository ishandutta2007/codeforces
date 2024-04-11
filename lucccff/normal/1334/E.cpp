#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

const int S = 9;
long long mult_mod(long long a,long long b,long long c){
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while(b){
        if(b & 1){
            ret += tmp;
            if(ret > c)ret -= c;//
        }
        tmp <<= 1;
        if(tmp > c)tmp -= c;
        b >>= 1;
    }
    return ret;
}

long long pow_mod(long long a,long long n,long long mod){
    long long ret = 1;
    long long temp = a%mod;
    while(n){
        if(n & 1)ret = mult_mod(ret,temp,mod);
        temp = mult_mod(temp,temp,mod);
        n >>= 1;
    }
    return ret;
}

bool check(long long a,long long n,long long x,long long t){
    long long ret = pow_mod(a,x,n);
    long long last = ret;
    for(int i = 1;i <= t;i++){
        ret = mult_mod(ret,ret,n);
        if(ret == 1 && last != 1 && last != n-1)return true;//
        last = ret;
    }
    if(ret != 1)return true;
    else return false;
}

bool Miller_Rabin(long long n){
    if( n < 2)return false;
    if( n == 2)return true;
    if( (n&1) == 0)return false;//
    long long x = n-1;
    long long t = 0;
    while( (x&1)==0 ){x >>= 1; t++;}
    srand(time(NULL));/* *************** */
    for(int i = 0;i < S;i++){
        long long a = rand()%(n-1) + 1;
        if( check(a,n,x,t) )
        return false;
    }
    return true;
}

long long factor[100];//
int tol;// 0tol-1
long long gcd(long long a,long long b){
    long long t;
    while(b){
        t = a;
        a = b;
        b = t%b;
    }
    if(a >= 0)return a;
    else return a;
}

long long pollard_rho(long long x,long long c){
    long long i = 1, k = 2;
    srand(time(NULL));
    long long x0 = rand()%(x-1) + 1;
    long long y = x0;
    while(1){
        i ++;
        x0 = (mult_mod(x0,x0,x) + c)%x;
        long long d = abs(__gcd(y-x0,x));
        if( d != 1 && d != x)return d;
        if(y == x0)return x;
        if(i == k){y = x0; k += k;}
    }
}

void findfac(long long n,int k){
    if(n == 1)return;
    if(Miller_Rabin(n))
    {
        factor[tol++] = n;
        return;
    }
    long long p = n;
    int c = k;
    while(p>=n) p=pollard_rho(p,c--);
    findfac(p,k);
    findfac(n/p,k);
}
/*118 //POJ 1811
119 //N(2 <= N < 2^54),, "Prime", 
120 int main(){
121 int T;
122 long long n;
123 scanf("%d",&T);
124 while(T){
125 scanf("%I64d",&n);
126 if(Miller_Rabin(n))printf("Prime\n");
127 else{
128 tol = 0;
kuangbin 31
ACM Template of kuangbin
129 findfac(n,107);
130 long long ans = factor[0];
131 for(int i = 1;i < tol;i++)
132 ans = min(ans,factor[i]);
133 printf("%I64d\n",ans);
134 }
135 }*/



int main(){
    long long i,j,k,l,m,n,x,p,q,y,a,b,ans;
    long long jie[200],ijie[200],inv[200];
    jie[0]=jie[1]=j=1;
    ijie[0]=ijie[1]=k=1;
    inv[1]=1;
    m=MOD;
    for(i=2;i<200;i++) {
        j=j*i%MOD;
        jie[i]=j;
        inv[i]=inv[m%i]*(m-m/i)%MOD;
        k=k*inv[i]%MOD;
        ijie[i]=k;
    }
    cin>>x>>q;
    findfac(x,107);
    sort(factor,factor+tol);
    for(i=0;i<q;i++) {
        cin>>k>>l;
        p=__gcd(k,l);
        if (p<k&&p<l) {
            k=k/p;
            l=l/p;
            a=0;
            b=0;
            ans=1;
            for(j=0;j<tol;j++) {
                y=0;
                while (k%factor[j]==0) {
                    k/=factor[j];
                    a++;
                    y++;
                }
                ans=(ans*ijie[y])%MOD;
                if (k==0) break;
            }
            for(j=0;j<tol;j++) {
                y=0;
                while (l%factor[j]==0) {
                    l/=factor[j];
                    b++;
                    y++;
                }
                ans=(ans*ijie[y])%MOD;
                if (l==0) break;
            }
            ans=(jie[a]*jie[b]%MOD)*ans%MOD;
            cout<<ans<<endl;
        }
        else if (p==k) {
            l=l/p;
            b=0;
            ans=1;
            for(j=0;j<tol;j++) {
                y=0;
                while (l%factor[j]==0) {
                    l/=factor[j];
                    b++;
                    y++;
                }
                ans=(ans*ijie[y])%MOD;
                if (l==0) break;
            }
            cout<<(ans*jie[b]%MOD)<<endl;
        }
        else {
            l=k/p;
            b=0;
            ans=1;
            for(j=0;j<tol;j++) {
                y=0;
                while (l%factor[j]==0) {
                    l/=factor[j];
                    b++;
                    y++;
                }
                ans=(ans*ijie[y])%MOD;
                if (l==0) break;
            }
            cout<<(ans*jie[b]%MOD)<<endl;
        }
    }
    return 0;
}