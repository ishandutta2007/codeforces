#include <bits/stdc++.h>
using namespace std;

long double const pi = acos(-1.0);

struct coord {
    long double x;
    long double y;
    long double angle;
    int id;
    coord(){}
    coord(int x, int y, int i): x(x), y(y), id(i) {
        angle = atan2(y,x);
    }
};
bool cmp ( coord a, coord b) {
    return ( a.angle > b.angle);
}

coord a[100000 + 10];

long double eps = 1e-10;

int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
   int n;
   cin>>n;
   for ( int i = 0; i < n; i++) {
      int x,y;
      cin>>x>>y;
      a[i] = coord(x,y,i);
   }
   sort(a,a+n,cmp);
   int curri,currj;
   long double ans = 100;
   long double t;
   for ( int i = 0; i < n - 1 ; i++) {
        t = min(2*pi - (a[i].angle - a[i+1].angle),a[i].angle - a[i+1].angle);
        if ( ans > t) {
            ans = t;
            curri = a[i].id;
            currj = a[i+1].id;
   }
   t = min(2*pi - (a[0].angle - a[n-1].angle),a[0].angle - a[n-1].angle);
   if ( ans > t) {
    curri = a[0].id;
    currj = a[n-1].id;
    }
   }
   cout<<curri + 1<<" "<<currj + 1;
   return 0;
}