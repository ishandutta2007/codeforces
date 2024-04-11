#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int EulerPhiEasy(int n){
  int i,k,ret=n;
  for(i=2;i*i<=n;i++) if(n%i==0){
    while(n%i==0) n/=i;
    ret = ret/i*(i-1);
  }
  if(n>1) ret = ret/n*(n-1);
  return ret;
}

char a[1111111], b[1111111]; int C;

ll pw(ll a,ll b,ll m){
  ll r;
  if(b==0) return 1%m;
  r = pw(a,b/2,m);
  r=(r*r)%m;
  if(b%2) r=(r*a)%m;
  return r;
}

int main(){
  int i,j,k,l,m,n;
  ll A, B, phi, res;

  scanf("%s%s%d",a,b,&C);

  A = 0;
  for(i=0;;i++){
    if(a[i]<' ') break;
    A = A*10 + a[i]-'0';
    A %= C;
  }
  res = (A+C-1)%C;

  phi = EulerPhiEasy(C);
  for(i=0;;i++) if(b[i]<' ') break;
  if(i<15){
    B = 0;
    for(i=0;;i++) if(b[i]<' ') break; else B=B*10+b[i]-'0';
  } else {
    B = 0;
    for(i=0;;i++) if(b[i]<' ') break; else B=(B*10+b[i]-'0')%phi;
    B += phi+phi;
  }

  res = (res * pw(A,B-1,C))%C;
  if(res==0) res += C;
  
  printf("%d\n",(int)res);

  return 0;
}