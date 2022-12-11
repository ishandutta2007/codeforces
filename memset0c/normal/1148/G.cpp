//xyrQQ3235652112
#include<bits/stdc++.h>
#undef assert
#define assert(f) if(!(f))printf("Assert: Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__),exit(0)
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
template<class T> inline T gcd(T n,T m){return m?gcd(m,n%m):n;}
template<const int N> struct Prime:std::vector<int>{
  Prime(){
    std::vector<bool> vis(N);
    for(int i=2;i<N;i++){
      if(!vis[i])this->push_back(i);
      for(int j:*this){if(i*j>=N)break; vis[i*j]=true; if(!(i%j))break;}
    }
  }
};
const int N=1e5+10,M=1e7+10;
int n,k,A,B,C,a[N],deg[N],v[N][8],l[N],f[M];
uint64_t sta[M];
Prime<10000> prime;
std::vector<int> pos;
std::unordered_map<int,int> primeid;
void affect(int *v,int l,int x){
  std::function<void(int,int)> dfs=[&](int i,int s){
    if(i==l){
      if(s!=1)f[s]+=x;
      return;
    }
    dfs(i+1,s);
    dfs(i+1,s*v[i]);
  };
  dfs(0,1);
}
int query(int *v,int l){
  int res=0;
  std::function<void(int,int)> dfs=[&](int i,int s){
    if(i==l){
      res+=s<0?-f[-s]:f[s];
      return;
    }
    dfs(i+1,s);
    dfs(i+1,s*-v[i]);
  };
  dfs(0,-1);
  return res;
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n),read(k);
  for(int i=1;i<=n;i++)read(a[i]);
  for(int i=0;i<prime.size();i++)primeid[prime[i]]=i;
  for(int x,i=1;i<=n;i++){
    x=a[i];
    for(int j=0;prime[j]*prime[j]<=x;j++)
      if(x%prime[j]==0){
        v[i][l[i]++]=prime[j];
        while(x%prime[j]==0)x/=prime[j];
      }
    if(x!=1)v[i][l[i]++]=x;
    // printf("a[%d]=%d : ",i,a[i]);
    // for(int x:v[i])printf("%d ",x); putchar('\n');
  }
  for(int i=1;i<=n;i++)affect(v[i],l[i],1);
  for(int i=1;i<=n;i++)deg[i]=query(v[i],l[i])-1;
  for(int i=1;i<=n;i++)affect(v[i],l[i],-1);
  // for(int i=1;i<=n;i++)printf("%d%c",deg[i]," \n"[i==n]);
  int fulldeg=0;
  for(int i=1;i<=n;i++)fulldeg+=deg[i]==n-1;
  if(fulldeg>=k){
    for(int i=1;i<=n;i++)if(deg[i]==n-1)pos.push_back(i);
  }else{
    for(int i=1;i<=n;i++)if(n-1-deg[i]>=2){
      A=i;
      for(int j=1;j<=n;j++)if(j!=A&&gcd(a[i],a[j])==1){
        if(!B){B=j; continue;}
        if(!C){C=j; continue;}
        break;
      }
      break;
    }
    // for(int i=1;i<=n;i++)printf("%d%c",deg[i]," \n"[i==n]);
    // printf("A=%d B=%d C=%d\n",A,B,C);
    if(A){
      assert(B&&C);
      auto getp=[&](int cur){
        std::vector<int> res;
        for(int i=1;i<=n&&res.size()<cur;i++)
          if(i!=A&&i!=B&&i!=C){
            res.push_back(i);
          }
        // assert(res.size()==cur);
        return res;
      };
      auto solve=[&](int cur){
        int res=0;
        std::vector<int> p=getp(cur);
        for(int i:p)affect(v[i],l[i],1);
        for(int i:p)deg[i]=query(v[i],l[i])-1;
        for(int i:p)affect(v[i],l[i],-1);
        for(int i:p)res+=deg[i]!=cur-1;
        return res;
      };
      int l=1,r=n-3,mid,res=-1;
      while(l<=r){
        mid=(l+r)>>1;
        solve(mid)+3>=k?(res=mid,r=mid-1):(l=mid+1);
      }
      assert(~res);
      int now=solve(res);
      std::vector<int> p=getp(res);
      for(int i:p)if(deg[i]!=res-1)pos.push_back(i);
      if(pos.size()<k)pos.push_back(A);
      if(pos.size()<k)pos.push_back(B);
      if(pos.size()<k)pos.push_back(C);
    }else{
      uint64_t all=0;
      std::vector<int> match(n+1);
      std::vector<uint64_t> hsh(n+1);
      std::map<uint64_t,int> map;
      std::mt19937_64 rng(20040725^std::chrono::steady_clock::now().time_since_epoch().count());
      for(int i=1;i<=n;i++)hsh[i]=rng(),all^=hsh[i],map[hsh[i]]=i;
      for(int i=1;i<=n;i++)
        for(int x=1;x<(1<<l[i]);x++){
          int s=1;
          for(int j=0;j<l[i];j++)
            if((x>>j)&1)s*=v[i][j];
          sta[s]^=hsh[i];
        }
      for(int i=1;i<=n;i++)if(deg[i]==n-2){
        uint64_t tem=all;
        for(int x=1;x<(1<<l[i]);x++){
          int s=1;
          for(int j=0;j<l[i];j++)
            if((x>>j)&1)s*=v[i][j];
          tem^=sta[s];
        }
        match[i]=map[tem];
        // assert(match[i]);
      }
      for(int i=1;i<=n;i++)
        if(!match[i]||i<match[i])
          pos.push_back(i);
    }
  }
  assert(pos.size()>=k);
  for(int i=0;i<k;i++)print(pos[i]," \n"[i+1==k]);
}