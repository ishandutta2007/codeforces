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
    int i,k,s=0,p=0;
    bool e=true;
 char *a;
 cin>>k;
 a=new char[k];
 cin>>a;
 for (i=0;i<=(k-1)/2;i++)
  if ( !(a[i]=='4' || a[i]=='7') || !(a[k-1-i]=='4' || a[k-1-i]=='7')  ) {e=false; break;} else
   {s+=a[i];p+=a[k-i-1];}
  if (!e || s!=p) cout<<"NO"; else cout<<"YES";
  // getch();
    return 0;
}