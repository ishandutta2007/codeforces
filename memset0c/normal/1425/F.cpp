#include<bits/stdc++.h>
const int N=1e3+10;
int n,a[N],s[N];
int main(){
  scanf("%d",&n);
  for(int i=2;i<=n;i++){
    printf("? %d %d\n",1,i);
  }
  printf("? 2 3\n");
  fflush(stdout);
  for(int i=2;i<=n;i++)scanf("%d",&s[i]);
  scanf("%d",&s[1]);
  for(int i=3;i<=n;i++)a[i]=s[i]-s[i-1];
  a[2]=s[1]-a[3];
  a[1]=s[2]-a[2];
  printf("! ");
  for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
}