#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
LL MOD = 1000000007;
LL powmod(LL a, LL k){
    if(k == 0) return 1;
    LL r = powmod(a,k/2);
    if(k%2) return (a*r % MOD)*r % MOD;
    return r*r % MOD;
}
int main() {
    LL n, x;
    cin >> n >> x;
    LL a[n];
    LL sum =0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum -= a[n-1];
    multiset<LL> mset;
    for(int i = 0; i < n; i++){
        mset.insert(a[n-1]-a[i]);
    }
    LL ans = 0;
    while(1){
        LL b = *mset.begin();
        if(mset.count(b) % x != 0){
            ans = b;
            break;
        } else {
            LL k = mset.count(b) / x;
            for(int i = 0; i < k; i++){
                mset.insert(b+1);
            }
            mset.erase(b);
        }
    }
    //cout << sum + min(ans,a[n-1]) << endl;
    cout << powmod(x,sum+min(ans,a[n-1])) << endl;
    return 0;
}