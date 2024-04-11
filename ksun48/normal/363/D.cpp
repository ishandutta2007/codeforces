#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, a;
    cin >> n >> m >> a;
    LL b[n];
    LL p[m];
    for(LL i = 0; i < n; i++) cin >> b[i];
    for(LL j = 0; j < m; j++) cin >> p[j];
    sort(b,b+n);
    sort(p,p+m);
    LL s = 0;
    LL e = min(n,m)+1;
    while(s+1<e){
        LL use = 0;
        LL mid = (s+e)/2;
        for(int i = 0; i < mid; i++){
            if(p[i] > b[i+n-mid]){
                use += p[i]-b[i+n-mid];
            }
        }
        if(use <= a){
            s= mid;
        } else {
            e = mid;
        }
    }
    cout << s << endl;
    LL price = 0;
    for(int i = 0; i < s; i++){
        price += p[i];
    }
    cout << max(0LL, price-a) << endl;
    return 0;
}