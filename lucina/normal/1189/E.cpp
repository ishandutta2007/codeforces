#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,p,k,mod,ans;
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

int main(){
    vector<int> a;
    scanf("%d%d%d",&n,&mod,&k);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a.push_back(sub(power(x,4),mul(x,k)));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int j=i;
        while(a[j]==a[i]&&j<n){
                ans+=(j-i);
                j++;
        }
        i=j-1;
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/