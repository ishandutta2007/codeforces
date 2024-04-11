#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int get(int a, int b){
    int lo = 1, hi = a+1;

    while (lo + 1 < hi){
        int mid = (lo + hi) >> 1;

        if (a / mid < b)
            hi = mid;
        else
            lo = mid;
    }

    if (a / lo == b)
        return lo;
    else
        return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0){
        int q; cin >> q;

        if (q == 0){
            cout << "1 1" << endl;
            continue;
        }

        bool ok = false;

        for (int i = 1; !ok && i * i <= q; ++i){
            if (q % i == 0){
                int u = i, v = q / i;
                
                if ((u & 1) != (v & 1))
                    continue;

                int a = (u + v) / 2;
                int b = (v - u) / 2;

                int c = get(a, b);

                if (c == -1) continue;

                cout << a << " " << c << endl;
                ok = true;
            }
        }

        if (!ok) cout << -1 << endl;
    }

    return 0;
}