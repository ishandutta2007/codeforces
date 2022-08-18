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


int main(){
    string s; bool e=false;
    int i,k;
 cin>>s;
   
    int n=s.length();
    for (i=0; i<n ;i++) if (s[i]=='H' || s[i]=='Q' || s[i]=='9') {e=true; break;}
    if (e) cout<<"YES"; else cout <<"NO";
   // getch();
    return 0;
}