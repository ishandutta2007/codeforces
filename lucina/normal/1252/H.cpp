#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,p,k,mod,ans;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}
int power(int a,int b) {
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
unordered_map<int,int> ss;

int main(){
    // ss.reserve(1<<17);
    // ss.max_load_factor(0.25);
    scanf("%d%d%d",&n,&mod,&k);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        int s=(sub(power(x,4),mul(x,k)));
        ans+=ss[s];
        ss[s]++;
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/