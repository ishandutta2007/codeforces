#include<bits/stdc++.h>
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
std::mt19937 rng(20040725^std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
const int N=2e5+10;
int n;
long long a[N];
std::set<long long> checked,calced;
long long check(long long x){
  if(checked.count(x))return LLONG_MAX;
  checked.insert(x);
  long long ans=0;
  for(int i=1;i<=n;i++)if(a[i]<=x){
    ans+=x-a[i];
  }else{
    ans+=std::min(a[i]%x,x-a[i]%x);
  }
  return ans;
}
long long calc(long long x){
  if(!x||calced.count(x))return LLONG_MAX;
  calced.insert(x);
  long long ans=LLONG_MAX;
  // printf("check %lld => ",x);
  for(long long i=2;i*i<=x;i++)if(x%i==0){
    ans=std::min(ans,check(i));
    while(x%i==0)x/=i;
  }
  if(x!=1)ans=std::min(ans,check(x));
  // printf("%lld\n",ans);
  return ans;
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n),srand(20040725);
  for(int i=1;i<=n;i++)read(a[i]);
  for(int i=n;i>=1;i--)std::swap(a[i],a[rand(1,i)]);
  long long ans=LLONG_MAX;
  for(int k=1;k<=n&&clock()/(double)CLOCKS_PER_SEC<.1;k++){
    ans=std::min(ans,calc(a[k]));
    ans=std::min(ans,calc(a[k]+1));
    ans=std::min(ans,calc(a[k]-1));
  }
  printf("%lld\n",ans);
}