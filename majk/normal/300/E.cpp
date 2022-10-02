#include <iostream>
#include <vector>

template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}

typedef long long ll;
using namespace std;
constexpr int M = 1e7+6;
constexpr ll UP = 1e14;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    vector<int> S(M, 0);
    for (int i = 2; i < M; ++i) {
        if (S[i] == 0) {
            for (int j = i; j < M; j += i) S[j] = i;
        }
    }

    vector<ll> C(M, 0), F(M, 0);
    int K; cin >> K;
    for (int i = 0; i < K; ++i) {
        int a; cin >> a;
        C[a]++;
    }

    for (int i = M-1; i > 1; --i) C[i-1] += C[i];
    for (int i = M-1; i > 1; --i) C[i/S[i]] += C[i];
    for (int i = M-1; i > 1; --i) F[S[i]] += C[i];

    ll ans = 1;
    for (int i = M-1; i > 1; --i) {
        if (F[i]) {
            auto check = [&](ll up) {
                    ll cnt = 0;
                    ll x = i;
                    while (up/x) {
                        cnt += up/x;
                        x *= i;
                    }
                    return cnt >= F[i];
            };
            if (!check(ans)) {
                ans = bsl(ans+1, i*F[i], check);
            }
        }
    }
    cout << ans << endl;
}