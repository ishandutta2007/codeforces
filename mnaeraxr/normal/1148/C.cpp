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

    vector<int> val(n);
    vector<int> inv(n);

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        v--;
        val[i] = v;
        inv[v] = i;
    }

    vector<pii> answer;
    int m = n / 2;

    auto s = [&](int i, int j){
        swap(val[i], val[j]);
        inv[val[i]] = i;
        inv[val[j]] = j;
        answer.push_back({i + 1, j + 1});
    };

    for (int i = 1; i + 1 < n; ++i){
        int p = inv[i];
        int v = i;

        if (v < m) {
            if (p >= m){
                s(p, 0);
                s(0, n - 1);
            } else {
                s(p, n - 1);
            }
            s(n - 1, v);
        } else {
            if (p < m){
                s(p, n - 1);
                s(n - 1, 0);
            } else {
                s(p, 0);
            }
            s(0, v);
        }

        // for (int j = 0; j < n; ++j)
        //     cout << val[j] + 1 << " ";
        // cout << endl;
        // cout.flush();
    }

    if (val[0] != 0)
        s(0, n - 1);

    for (int i = 0; i < n; ++i){
        assert(val[i] == i);
    }

    assert(answer.size() <= 5 * n);

    cout << answer.size() << endl;

    for (auto x : answer)
        cout << x.first << " " << x.second << endl;

    return 0;
}