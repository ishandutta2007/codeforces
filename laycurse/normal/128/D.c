#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}


int in[120000];
int num[120000];

int main(){
  int i,j,k,l,m,n;
  int rest, dame;
  int las;
  
  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);
    if(n%2){ puts("NO"); continue; }
    
    intSort(in, n);

    if(in[n-1] >= in[0] + n){ puts("NO"); continue; }

    rep(i,n) num[i] = 0;
    rep(i,n) num[in[i]-in[0]]++;

    rest = n;
    num[0]--; rest--; las = 0; dame = 0;
    for(;;){
/*      printf("%d : %d : ",las,rest); rep(i,5) printf("%d ",num[i]); puts("");*/
      
      if(rest==1){
        if(num[las+1]) break;
        dame = 1; break;
      }

      if(num[las]){
        if(num[las+1]==0){dame=1; break;}
        num[las]--; num[las+1]--; rest -= 2;
        continue;
      }

      if(num[las+1]<=1){ dame=1; break; }
      num[las+1]-=2; las++; rest -= 2;
    }

    if(dame)puts("NO"); else puts("YES");
  }

  return 0;
}