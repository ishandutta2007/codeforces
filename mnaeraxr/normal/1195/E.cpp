#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int val[3001][3001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    int g0, x, y, z;

    cin >> n >> m >> a >> b;
    cin >> g0 >> x >> y >> z;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            val[i][j] = g0;
            g0 = (1LL * g0 * x + y) % z;
        }
    }

    for (int i = 0; i < n; ++i){
        deque<pii> d;
        for (int j = 0; j + 1 < b; ++j){
            while (!d.empty() && d.back().second >= val[i][j])
                d.pop_back();
            d.push_back(pii(j, val[i][j]));
        }

        for (int j = b - 1; j < m; ++j){
            while (!d.empty() && d.back().second >= val[i][j])
                d.pop_back();

            d.push_back(pii(j, val[i][j]));
            val[i][j - b + 1] = d.front().second;

            // cerr << val[i][j] << " ";

            if (d.front().first == j - b + 1)
                d.pop_front();
        }

        // cerr << endl;
    }

    int64 answer = 0;

    // cerr << "*" << endl;

    for (int j = 0; j < m - b + 1; ++j){
        deque<pii> d;
        for (int i = 0; i + 1 < a; ++i){
            while (!d.empty() && d.back().second >= val[i][j])
                d.pop_back();
            d.push_back(pii(i, val[i][j]));
        }

        for (int i = a - 1; i < n; ++i){
            while (!d.empty() && d.back().second >= val[i][j])
                d.pop_back();

            d.push_back(pii(i, val[i][j]));
            answer += d.front().second;

            // cerr << d.front().second << " ";

            if (d.front().first == i - a + 1){
                d.pop_front();
            }
        }

        // cerr << endl;
    }

    cout << answer << endl;

    return 0;
}