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
    scids(s);
    int ca = 0;
    int cd = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            ca++;
        } else {
            cd++;
        }
    }

    if (ca > cd) {
        cout << "Anton";
    } else if (cd > ca) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }

    return 0;
}