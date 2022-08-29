#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int i,j,k,l,m,n;
  int x,y,z;
  ll cx, cy, cz;
  ll res;

  while(scanf("%d%d%d%d",&x,&y,&z,&k)==4){
    cx = cy = cz = 1;

    while(k>0){
      if(cx==x && cy==y && cz==z) break;
      if(k>0 && cx<x) cx++, k--;
      if(k>0 && cy<y) cy++, k--;
      if(k>0 && cz<z) cz++, k--;
    }

    res = cx * cy * cz;
    printf("%I64d\n",res);
  }


  return 0;
}