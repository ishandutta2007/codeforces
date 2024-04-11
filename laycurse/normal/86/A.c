#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll pw[30];

ll ref(ll a){
  int i, now=0;
  ll res = 0;

  while(a){
    res += pw[now] * (9 - (a%10));
    now++; a/=10;
  }

  return res;
}

int main(){
  int i,j,k,l,m,n;
  int a,b;
  ll res, tmp, go;

  pw[0] = 1;
  REP(i,1,30) pw[i] = pw[i-1]*10;

  while(scanf("%d%d",&a,&b)==2){
    res = 0;
    REP(i,1,15){
      go = pw[i] / 2;
      if(go < a) go = a;
      if(go > b) go = b;
      tmp = go * ref(go);
      if(res < tmp) res = tmp;
    }
    printf("%I64d\n",res);
  }

  return 0;
}