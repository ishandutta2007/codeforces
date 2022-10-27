#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
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
int n,p[maxn],l[maxn],r[maxn];
///p[i] is the probability that x[i]!=x[i-1]
int calc(int i){
    int s=0;
    if(i>1){
        int ct=max(0,min({r[i],r[i-1],r[i+1]})-max({l[i],l[i-1],l[i+1]})+1);
        s=mul(ct,power(mul(r[i]-l[i]+1,mul(r[i+1]-l[i+1]+1,r[i-1]-l[i-1]+1)),mod-2));
    }
    return add(s,sub(1,sub(2,add(p[i],p[i+1]))));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(min(r[i],r[i-1])<max(l[i],l[i-1]))p[i]=0;
        else
        p[i]=mul(sub(min(r[i]+1,r[i-1]+1),max(l[i],l[i-1])),power(mul(r[i]-l[i]+1,r[i-1]-l[i-1]+1),mod-2));
        p[i]=sub(1,p[i]);
        plusle(sum,p[i]);
    }
    int ans=0;
    ///case i==j
    for(int i=1;i<=n;i++){
        plusle(ans,p[i]);
    ///case |i-j|>1
        int cur=sum;
        if(i>1)minun(cur,p[i-1]);
        if(i<n)minun(cur,p[i+1]);
        minun(cur,p[i]);
        cur=mul(p[i],cur);
        plusle(ans,cur);
    ///|i-j|==1
        ///E(I(a)I(a+1))==1-(1-p[a])-(1-p[a+1])+prob(x[i])
        if(i>1)plusle(ans,calc(i-1));
        if(i<n)plusle(ans,calc(i));
    }
    printf("%d\n",ans);

}