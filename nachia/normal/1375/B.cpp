#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL H,W;

void Case(){
 scanf("%u%u",&H,&W);
 bool ok=true;
 rep(y,H) rep(x,W){
  UL a; scanf("%u",&a);
  UL c=4;
  if(x==0)c--; if(x==W-1)c--;
  if(y==0)c--; if(y==H-1)c--;
  if(c<a) ok=false;
 }
 printf(ok?"YES\n":"NO\n");
 if(!ok) return;
 rep(y,H) {
  rep(x,W){
   UL c=4;
   if(x==0)c--; if(x==W-1)c--;
   if(y==0)c--; if(y==H-1)c--;
    if(x) printf(" ");
   printf("%u",c);
  } printf("\n");
 }
}

int main() {
 UL T; scanf("%u", &T);
 rep(t,T) Case();
 return 0;
}