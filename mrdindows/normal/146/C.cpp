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
  char *a,*b;
  long i,k,n,s=0,p=0;
  a=new char[100001];
  b=new char[100001];
  cin>>a; cin>>b;
  for (i=0;i<=strlen(a);i++)
   if (a[i]!=b[i]) {if (a[i]=='4') s++; else p++;}
   cout<<max(s,p);
 //  getch();
    return 0;
}