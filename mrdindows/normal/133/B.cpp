//#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//#include <conio.h>
#include <cmath>
#include <stdio.h>
//#include <fstream>
#include <cstdio>
//#include <map>
//#include <set>
#include <string.h>
using namespace std;
//#pragma comment(linker, "/STACK:167772160")

#define sz(x) int((x).size())
#define inf 1000000000
#define pb push_back
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,a,b) for(i=a;i<b;i++)
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp make_pair
typedef long long ll;
#define y1 kjdh
#define y0 sf
const long m=1000003;
int cena(char s) {
    if (s=='>') return 8;
    if (s=='<') return 9;
    if (s=='+') return 10;
    if (s=='-') return 11;
    if (s=='.') return 12;
    if (s==',') return 13;
    if (s=='[') return 14;
    if (s==']') return 15;
}

long long int step(long long n,int k) {


     if (k==1) return n; else
      if (k==0) return 1; else
       return (  step( ((n%m)*(n%m))%m,k/2)*step(n,k%2))%m;
}


ll st(ll x, ll y, ll m) {
     if (y==1) return x%m; else
      if (y==0) return 1; else
       return (  st( (  (ll)  (x%m)  *  (x%m)   )%m  ,y/2,m)*st(x,y%2,m)%m); }


int main(){
     char *a=new char[101];
     bool e=false;
     int i,k,p,j;
     ll s=0;
     cin>>a;
     int n=strlen(a);
     for (i=0;i<n;i++){
         s=(s+cena(a[i])*step(2,4*(n-1-i)))%m;
         
         
         
         }
     cout<<s<<endl;

      
         
         
         
         
         
         
  //   getch();
     return 0;
 
}