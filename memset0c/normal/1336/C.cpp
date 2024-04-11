#include<bits/stdc++.h>
#include <climits>
#include <queue>
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
  if(x<0)putchar('-'),x=-x;
  if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=3e3+10,mod=998244353;
int n,m;
char a[N],b[N];

struct z {
  int x;
  z(int x=0):x(x){}
  friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
  friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
  friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}ans,f[N][N];

inline bool check(char c,int k){
  if(k>m)return true;
  return c==b[k];
}

int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  scanf("%s",a+1),n=strlen(a+1);
  scanf("%s",b+1),m=strlen(b+1);
  for(int i=1;i<=n;i++)if(check(a[1],i)){
    f[i][i]=1;
  }
  for(int len=1;len<n;len++){
    for(int l=1,r=len;r<=n;l++,r++)if(f[l][r].x){
      // printf("> %d %d : %d\n",l,r,f[l][r].x);
      if(l>1&&check(a[len+1],l-1))f[l-1][r]=f[l-1][r]+f[l][r];
      if(r<n&&check(a[len+1],r+1))f[l][r+1]=f[l][r+1]+f[l][r];
    }
  }
  for(int i=m;i<=n;i++){
    ans=ans+f[1][i]*2;
  }
  print(ans.x,'\n');
}