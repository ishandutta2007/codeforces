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

int zerk (char s) { 
     char k=0;
     for(int i=0;i<4;i++) 
     k=k+(s/((int)(pow(2.0,i)))%2)*pow(2.0,7-i)+(s/((int)(pow(2.0,7-i)))%2)*pow(2.0,i);
     
     
     if (k<0) return k+256; else return k;
     
     }

int main(){
    char *s=new char[101]; 
    int i,k,b;
 gets(s);
   
    int n=strlen(s);
    for (i=0; i<n ;i++) {
        b=zerk(s[i-1])-zerk(s[i])%256;
        if (b<0) b+=256;
        cout<<b<<endl;
      
        
        }

//   getch();
    return 0;
}