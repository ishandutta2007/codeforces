#include <bits/stdc++.h>
using namespace std;
struct cell {
    int x;
    int y;
    int t;
};
int n,m,q,k;

int f[600][600];

cell l[500*500 + 10];

bool cmp ( cell a, cell b) {
    return ( a.t < b.t );
}

bool ans ( int t ) {
    for ( int i = 0; i <= n; i++) {
        for ( int j = 0; j <= m; j++) {
            f[i][j] = 0;
        }
    }
    for ( int i = 1; i <= q; i ++) {
        if ( l[i].t <= t) {
            f[l[i].x][l[i].y] = 1;
        }
        else break;
    }
    for ( int i = 1; i <= n; i ++ ) {
        for ( int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j] + f[i][j-1] + f[i][j] - f[i-1][j-1];
            if ( i >= k && j>= k ) {
               if ( f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k] == k*k ) {
                return true;
               }
            }
        }
    }
    return false;
}

int main()
{
     ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m>>k>>q;
   for (int i = 1; i <= q; i++) {
        cin>>l[i].x>>l[i].y>>l[i].t;
   }
   sort (l + 1, l + 1 + q, cmp);
   int le = -1;
   int ri = 1e9;
   int mid;
   if ( !ans(ri) ) {
    cout<<-1<<endl;
    return 0;
   }
   while ( ri - le > 1) {
        mid = (ri + le)/2;
        if ( ans(mid) ) {
            ri = mid;
        }
        else le = mid;
   }
   cout<<ri<<endl;
   return 0;
}