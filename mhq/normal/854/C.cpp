#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

pair<int,int> c[300000+3];

int f [300000+3];

set <int> nee;

int main()
{   ios_base::sync_with_stdio(false);
    int n,k;
    long long ans = 0;
    cin>>n>>k;
    for ( int i = 1; i <= n; i ++){
        cin>>c[i].first;
        c[i].second = i;
    }
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);
    for ( int i = 1; i<= n; i++) {
        nee.insert( k + i);
    }
    for ( int i = 1; i<= n; i++) {
        set<int>::iterator t = nee.lower_bound(c[i].second);
        f[c[i].second] = *t;
        ans += 1ll*c[i].first*( f[c[i].second]- c[i].second);
        nee.erase(t);
    }
    cout<<ans<<endl;
    for (int i =1; i<=n; i++ ) {
        cout<<f[i]<<" ";
    }

     return 0;
}