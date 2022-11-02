#include <stdio.h>
#include <algorithm>

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","rt",stdin);
  freopen("output.txt","wt",stdout);
  #endif
  int n,k,s,i,a[2000];
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
	  scanf("%d",&a[i]);
  }
  s=0;
  std::sort(a,a+n);
  while((a[3*(s+1)-1]<=5-k) && (3*(s+1)-1<n)){
	  s=s+1;
  }
  printf("%d",s);
}