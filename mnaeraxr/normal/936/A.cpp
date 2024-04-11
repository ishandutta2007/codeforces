#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int64 k, d, t;

    cin >> k >> d >> t;

    int64 f = ((k + d - 1) / d) * d;
    int64 a = k, b = f - k;

    int64 final = 2 * t;
    int64 piece = 2 * a + b;

    int64 full_steps = (final / piece);

    final -= full_steps * piece;
    full_steps *= f;

    bool half = false;

    if (final <= 2 * k){
        if (final & 1){
            half = true;
            final--;
        }

        full_steps += final / 2;
    }
    else{
        full_steps += k;
        final -= 2 * k;
        full_steps += final;
    }

    cout << full_steps;

    if (half) cout << ".5";

    cout << endl;

    return 0;
}