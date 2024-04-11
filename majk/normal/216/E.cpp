#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int K, B, N; cin >> K >> B >> N;

    int zeros = 0;
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    ll ans = 0, ansZero = 0;
    int pref = 0;
    for (int i = 0; i < N; ++i) {
        int a; 
        cin >> a;

        if (!a) { zeros++; ansZero += zeros; } else zeros = 0;
        pref = (pref + a) % (K-1);

        ans += cnt[(pref-B+K-1)%(K-1)];
        cnt[pref]++;
    }

    if (B == 0) {
        cout << ansZero << endl;
    } else if (B == K-1) {
        cout << ans - ansZero << endl;
    } else {
        cout << ans << endl;
    }
}