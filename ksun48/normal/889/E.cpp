#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n;
    cin >> n;
    LL a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0 && a[i] > a[i-1]) a[i] = a[i-1];
    }
    map<LL,LL> d;
    d[0] = 0;

    for(LL i = 0; i < n; i++){
        LL best = 0;
        while(1){
            LL v = -(*d.begin()).first;
            if(v < a[i]) break;
            LL p = d[-v];
            best = max(best, p + i * ((v+1-a[i]) - (v+1) % a[i]) );
            d.erase(-v);
            LL newv = v % a[i];
            d[-newv] = max(d[-newv], p + i*(v - newv));
        }
        d[-(a[i]-1)] = max(d[-(a[i]-1)], best);
    }
    LL ans = 0;
    for(auto it : d){
        ans = max(ans, -n*(it.first) + it.second);
    }
    cout << ans << endl;
}