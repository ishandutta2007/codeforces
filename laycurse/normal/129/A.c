#include<stdio.h>

int main(){
  int k, n, odd=0, even=0;

  scanf("%d",&n);
  while(n--){
    scanf("%d",&k);
    if(k%2) odd++; else even++;
  }

  if(odd%2==0) printf("%d\n",even); else printf("%d\n",odd);

  return 0;
}