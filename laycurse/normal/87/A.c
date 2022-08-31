#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll GCD(ll a,ll b){ll r; while(a){r=b; b=a; a=r%a;} return b;}
ll LCM(ll a,ll b){return a/GCD(a,b)*b; }

int main(){
  int i,j,k,l,m,n;
  ll a, b;
  ll a_time, b_time, end_time;
  ll a_next, b_next;
  ll now_time;

  while(scanf("%d%d",&i,&j)==2){
    a=i; b=j;

    now_time = 0;
    a_time = b_time = 0;
    end_time = LCM(a,b);

    while(now_time < end_time){
      a_next = now_time / a * a + a;
      b_next = now_time / b * b + b;

      if(a_next == b_next){
        if(a > b) b_next++;
        else      a_next++;
      }

      if(a_next < b_next){
        a_time += a_next - now_time;
        now_time = a_next;
      } else {
        b_time += b_next - now_time;
        now_time = b_next;
      }
    }

    if(a_time==b_time){ puts("Equal"); continue; }
    if(a_time > b_time) puts("Dasha"); else puts("Masha");
  }

  return 0;
}