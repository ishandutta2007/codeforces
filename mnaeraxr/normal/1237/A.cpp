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

    int n; cin >> n;

    int x = 0;

    int sum = 0;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;

        if (abs(v) % 2 == 0){
            cout << v / 2 << endl;
            sum += v / 2;
        } else {
            int s = v < 0 ? -1 : +1;

            v /= 2;

            if (x == 0 && s == -1)
                v--;
            else if (x == 1 && s == +1)
                v++;

            x = 1 - x;

            cout << v << endl;
            sum += v;
        }
    }

    assert(sum == 0);

    return 0;
}