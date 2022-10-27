#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a,int b) {
  a+=b;
  return a>=mod?a-mod:a;
}
int sub(int a,int b) {
  a-=b;
  return a<0?a+mod:a;
}
int mul(int a,int b) {
  return (int)((long long)a*b%mod);
}
int power(int a,int b) {
  int res=1;
  while (b>0) {
    if (b&1) {
      res=mul(res,a);
    }
    a=mul(a,a);
    b>>=1;
  }
  return res;
}

const int N=4010;
int n,k,l,fac[N],invf[N],p[2002];
int ncr(int N,int R){
    if(R==0||R==N)return 1;
    return mul(fac[N],mul(invf[N-R],invf[R]));
}
///p[x]=2*x(1-x)
///f[x]=sum i=k to n (n choose i)*(p[x]^i)*((1-p[x])^(n-i))
///integrate from 0 to one
///wolfram can help you strike it
///ok maybe I have to calculate this by myself

int main(){
    scanf("%d%d%d",&n,&k,&l);
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=mul(fac[i-1],i);
    invf[N-1]=power(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        invf[i]=mul(i+1,invf[i+1]);
    }
    invf[0]=1;
    for(int i=k;i<=n;i++){
        for(int j=0;j<=(n-i);j++){
            int cur=mul(ncr(n,i),ncr(n-i,j));
            if(j%2==0)
                plusle(p[i+j],cur);
            else
                minun(p[i+j],cur);
        }
    }
    ///ok now we have coefficient
    ///it's so brute but wolfram is a magic
    ///here magic comes!
    ///integrate x^i(1-x)^i=(i)!)^2/(2i+1)!
    int ans=0,p2=1;
    ///ok don't forgot stupid thing like f[x]=(2*x(1-x))^i
    for(int i=1;i<=n;i++){
        p2=mul(p2,2);
        int cur=(mul(mul(fac[i],fac[i]),invf[(2*i)+1]));
        cur=mul(cur,p[i]);
        cur=mul(cur,p2);
        plusle(ans,cur);
    }
    ans=mul(ans,l);
    printf("%d\n",ans);
}