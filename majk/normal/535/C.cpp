#include <iostream>

template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T, A, B; cin >> A >> B >> T;
    for (int i = 0; i < T; ++i) {
        ll l, t, m; cin >> l >> t >> m;
        ll h = bsh(l, ll(4e6), [&](int r) {
                    return A + B*(r-1) <= t && (A + B*(l-1) + A + B*(r-1)) * (r-l+1) / 2 <= t*m;
                });
        cout << h << '\n';
    }
}