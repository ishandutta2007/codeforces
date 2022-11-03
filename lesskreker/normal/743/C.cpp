#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    
    if (n <= 10) {
        for (int x = 1; x <= 100; x++) {
            for (int y = x + 1; y <= 100; y++) {
                for (int z = y + 1; z <= 100; z++) {
                    if ((x * y + y * z + x * z) * n == 2 * x * y * z) {
                        cout << x << " " << y << " " << z;
                        return 0;
                    }
                }
            }
        }
        cout << -1;
        return 0;
    }
    
    cout << n << " " << n + 1 << " " << n * (n + 1);

    return 0;
}