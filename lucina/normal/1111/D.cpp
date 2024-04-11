#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int dp[maxn],n,f[maxn],v[55],inv[maxn],dp2[maxn],ans[55][55],q;
char s[maxn];
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


int main(){
    scanf("%s",s+1);
    f[0]=1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        f[i]=mul(f[i-1],i);
        }
    inv[n]=power(f[n],mod-2);
    for(int i=n-1;i>=1;i--){
        inv[i]=mul(inv[i+1],i+1);
    }
    for(int i=1;i<=n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            v[s[i]-'a'+1]++;
        }
        else{
            v[s[i]-'A'+27]++;
        }
    }
    int base=1;
    base=mul(base,mul(f[n/2],f[n/2]));
    for(int i=1;i<=52;i++){
        if(v[i])base=mul(base,inv[v[i]]);
    }
    dp[0]=1;
    for(int j=1;j<=52;j++){
        if(!v[j])continue;
        for(int i=n;i>=v[j];i--){
            dp[i]=add(dp[i],dp[i-v[j]]);
        }
    }
    for(int i=1;i<=52;i++)
        ans[i][i]=dp[n/2];
    for(int i=1;i<=52;i++){
        if(!v[i])continue;
        for(int j=0;j<=n;j++)
            dp2[j]=dp[j];
        for(int j=v[i];j<=n;j++)
            dp2[j]=sub(dp2[j],dp2[j-v[i]]);
        for(int j=i+1;j<=52;j++){
            if(!v[j])continue;
            for(int k=v[j];k<=n;k++)
                dp2[k]=sub(dp2[k],dp2[k-v[j]]);
            ans[i][j]=mul(dp2[n/2],2);
            ans[j][i]=ans[i][j];
            for(int k=n;k>=v[j];k--)
                dp2[k]=add(dp2[k],dp2[k-v[j]]);
        }
    }
    scanf("%d",&q);
    int x,y;
    while(q--){
        scanf("%d%d",&x,&y);
        if(s[x]>='a'&&s[x]<='z')x=s[x]-'a'+1;
        else x=s[x]-'A'+27;
        if(s[y]>='a'&&s[y]<='z')y=s[y]-'a'+1;
        else y=s[y]-'A'+27;
        printf("%d\n",mul(base,ans[x][y]));
    }
}