#include<bits/stdc++.h>
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
int n,ans,cnt,las;
std::string str;
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  std::cin>>n>>str;
  las=-1;
  for(int i=0;i<n;i++){
    (str[i]=='(')?cnt++:cnt--;
    if(cnt<0&&las==-1)las=i;
    if(cnt==0&&las!=-1)ans+=i-las+1,las=-1;
  }
  printf("%d",cnt?-1:ans);
  return 0;
}