#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0) {
        int n; cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j)
                cin >> a[j];
            a.swap(b);
        }

        int state = 0;
        int last = -1;

        bool ok = true;

        for (int i = 0; i < n; ++i){
            a[i] = b[i] - a[i];

            if (a[i] < 0)
            {
                ok = false;
                break;
            }

            if (a[i] == 0) {
                if (state == 1)
                    state = 2;
            } else {
                if (state == 0) {
                    state = 1;
                    last = a[i];
                } else if (state == 1) {
                    if (a[i] != last) {
                        ok = false;
                        break;
                    }
                } else if (state == 2) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}