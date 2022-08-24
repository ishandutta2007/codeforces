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
 ios_base::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 int ans = 0;
 for ( int a = 0; a <= n; a++ ) {
    int t = min(( n - a)/2, m - 2*a);
    if ( t < 0 ) {
        continue;
    }
    ans = max(ans,t+a);
 }
 cout<<ans;
   return 0;
}