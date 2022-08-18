//#include <vector>
#include <string>
#include <string.h>
//#include <algorithm>
#include <math.h>
#include <iostream>
//#include <conio.h>
#include <stdio.h>
//#include <fstream>
#include <cstdio>

using namespace std;


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

int main(){
    int i,k,p=0,j;
    ll a,b,l1,l2;
    bool e=true;
    cin>>a>>b;
    if (b>a) cout<<b; else {
       l1=(ll)(log(b)/log(10))+1;
     
     

      char *s=new char[10],*c=new char[10]; 
            for (j=0;j<=9;j++) s[j]=*"";
   for(i=0;i<l1;i++) {
   s[i]=(char) ((b/(ll)(pow(10,l1-i-1)+0.001))%10+48);
   }
 
   for (i=a+1;i<=1000000;i++) {
   for (j=0;j<=9;j++) c[j]=*"";
   k=0;
   l2=(ll)(log(i)/log(10))+1;
   j=0;            
   while (j<l2) {
   ll t=(i/(ll)(pow(10,l2-j-1)+0.001))%10;      
   if (t==4 || t==7) {c[k++]=(char) (t+48);}
   j++;
  }
  e=true;
   if (k!=l1) e=false;
   for(ll t=0;t<l2;t++) if (c[t]!=s[t]) e=false;
  if (e) {cout<<i; break;}
  }

       }
   
   
       
 //  getch();
    return 0;
}