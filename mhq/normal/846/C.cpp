#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int n;
long long s[5002];
long long a[5002];
pair<long long,int> f[5002];
pair<long long,int> g[5002];
int main()
{   cin>>n;
    f[0] = make_pair(0,0);
    s[0] = 0;
    for ( int i = 1; i<=n; i++) {
        cin>>a[i];
        s[i] = s[i - 1] + a[i];
        if ( f[i - 1].first > s[i]) {
            f[i] = make_pair(f[i-1].first, f[i-1].second);
        }
        else {
            f[i] = make_pair( s[i], i);
        }
    }
    g[n] = make_pair(s[n],n);
    for ( int i = n - 1; i>=0; i--) {
        if ( g[i+1].first > s[i]) {
            g[i] = make_pair( g[i+1].first, g[i+1].second );
        }
        else {
            g[i] = make_pair( s[i], i);
        }
    }
    long long curans = -1e12;
    int cura,curb,curc;
    for ( int i = 0; i <=n; i++) {
        if (curans < f[i].first - s[i] + g[i].first ) {
            curans = f[i].first - s[i] + g[i].first;
            cura = f[i].second;
            curb = i;
            curc = g[i].second;
        }
    }
    cout<<cura<<" "<<curb<<" "<<curc;
     return 0;
}