#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int n,dp[maxn],inv,ans;
vector<int> fact[maxn];
vector<int> p[maxn];
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a,int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int pie(int x,int y){
    //find the number of 1<=p<=m such that
    //__gcd(x,p)==y
    //how to find? Of course, PIEEEEEE(not dessert)
    //rewrite x=y*a-> p=y*b
    //by some well known property of gcd
    //problem reduce to finding 1<=b<=m/y such that
    //gcd__(a,b)==1;
    int ma=(n/y);
    x/=y;// x==a now
    //let's look at prime
    //b must not be divisible by any prime factor of x
    int mask=(1<<(p[x].size()));
    //imagine if p[x].size==3
    //the configuration you will consider will be
    //001 010 011 100 101 110 111
    //regroup it 001 010 100 011 1010 110 111
    //ok
    int cal=0;
    //shitty bitmask
    for(int i=1;i<mask;i++){
            int cnt=0,f=0,tot=1;
        for(int j=0;j<p[x].size();j++){
            if(i&(1<<j)){
                cnt++;
                tot*=(p[x][j]);
            }
        }
        f=ma/tot;
        cal+=(f*((cnt&1)?1:-1));
    }
    return ma-cal;
    //ok next step is dp
}

int main(){
    scanf("%d",&n);
    inv=power(n,mod-2);
    // good sieve
    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i)
            fact[j].push_back(i);
    }
    for(int i=2;i<=n;i++){
        if(p[i].size()==0){
            for(int j=i;j<=n;j+=i){
                p[j].push_back(i);
            }
        }
    }
    //end of sieve here
    //First, let's write some recursive formula
    //(dp[x]=summation of (dp[divisor of x])*(f(x,divisor))*inverse[modulo])
    for(int i=2;i<=n;i++){
        //left side
        int lhs=1,rhs=1;
        //compute right side;
        for(int x:fact[i]){
            rhs=add(rhs,mul(mul(dp[x],pie(i,x)),inv));
        }
        //ok finish computation let's look at next step
        lhs=sub(lhs,mul(n/i,inv));
        dp[i]=mul(rhs,power(lhs,mod-2));
    }
    ans=1;
    for(int i=2;i<=n;i++){
        ans=add(ans,mul(dp[i],inv));
    }
    printf("%d\n",ans);
}