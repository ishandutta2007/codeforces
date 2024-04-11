#include <bits/stdc++.h>
using namespace std;

int n,m;

vector < pair < int, int > > g[100500];

int x,y,w,u;

long long d[100500];

int p[100500];

priority_queue < pair < long long, int > > nee;

int main() {
 //freopen("input.txt", "r", stdin);
 //freopen("output.txt","w",stdout);
 int n,a,b;
 cin>>n>>a>>b;
 a = ( a + b + 1000*n) % n ;
 if ( a == 0) {
    cout<<n;
 }
 else {
    cout<<a;
 }
   return 0;
}