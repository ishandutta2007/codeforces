#include <bits/stdc++.h>
typedef int64_t ll;
#define e1 first
#define e2 second
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,q;
    cin >> n >> q;
    ll a[n];
    ll preo[n];
    cin >> a[0];
    preo[0] = a[0];
    for(ll i = 1; i < n; ++i){
        cin >> a[i];
        preo[i] = preo[i-1]+a[i];
    }
    ll pre[n];
    memcpy(pre,preo,n << 3);
    ll k;
    ll off = 0;
    while(q--){
        cin >> k;
        auto it = upper_bound(pre,pre+n,k+off);
        /* cerr << *it << endl; */
        if(it == pre+n){
            off = 0;
            cout << n << '\n';
        }
        else{
            off += k;
            cout << n-(it-pre) << '\n';
        }
    }
}