#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll solve(ll in[], char op[], int size){
  int i,j,k,s;
  ll res = 1000000000000000LL, tmp;
  ll send[4];

  if(size==1) return in[0];
  rep(i,size) REP(j,i+1,size){
    s=0;
    rep(k,size) if(k!=i && k!=j) send[s++]=in[k];
    if(op[0]=='+') send[s++] = in[i]+in[j];
    else           send[s++] = in[i]*in[j];
    tmp = solve(send,op+1,size-1);
    if(res > tmp) res = tmp;
  }

  return res;
}

int main(){
  int i,j,k,l,m,n;
  int in[4]; ll send[4], res;
  char buf[100];

  for(;;){
    k=0;
    rep(i,4) k += scanf("%d",in+i);
    if(k!=4) break;

    rep(i,4) send[i] = in[i];
    rep(i,3) scanf("%s",buf+i);
    res = solve(send,buf,4);

    printf("%I64d\n",res); break;
  }

  return 0;
}