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

    string s; cin >> s;

    vector<pii> x;

    int last = -1;
    int total = 0;

    for (auto c : s) {
        int cur = c - 'A';

        if (last != cur) {
            if (last != -1) {
                x.push_back({last, total});
            }
            last = cur;
            total = 1;
        } else {
            total++;
        }
    }

    x.push_back({last, total});

    if (x.size() % 2 == 0) {
        cout << 0 << endl;
    } else {
        int n = x.size();

        bool ok = x[n / 2].second >= 2;

        for (int i = 0; 2 * i < n && ok; ++i){
            if (x[i].first == x[n - i - 1].first && x[i].second + x[n - i - 1].second >= 3) {

            } else {
                ok = false;
            }
        }

        if (ok) {
            cout << x[n / 2].second + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}