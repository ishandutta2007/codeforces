#include<bits/stdc++.h>
#define u64 unsigned long long
const int S=1<<21; char ibuf[S],*iS,*iT;
#define getchar() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,S,stdin),(iS==iT?EOF:*iS++)):*iS++)
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int K=9,N=1<<K,T=100;
int n,k,t,cnt,x[T],y[T];
u64 a[N][N],b[N][N],s[N][N];
bool ta[N][N],tb[N][N];
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(k),n=1<<k;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      read(s[i][j]);
  read(t);
  for(int i=0;i<t;i++){
    read(x[i]),read(y[i]),--x[i],--y[i];
    ta[(x[i]-x[0]+n)&(n-1)][(y[i]-y[0]+n)&(n-1)]=1;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      a[i][j]=s[(i+x[0])&(n-1)][(j+y[0])&(n-1)];
  for(int i=0;i<k;i++){
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)if(ta[i][j])
        for(int x=0;x<n;x++)
          for(int y=0;y<n;y++)
            b[(i+x)&(n-1)][(j+y)&(n-1)]^=a[x][y];
    memcpy(a,b,sizeof(a));
    if(i+1!=k){
      memset(tb,0,sizeof(tb));
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)if(ta[i][j])
          tb[(i<<1)&(n-1)][(j<<1)&(n-1)]^=1;
      memcpy(ta,tb,sizeof(ta));
    }
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cnt+=(bool)a[i][j];
  printf("%d\n",cnt);
}