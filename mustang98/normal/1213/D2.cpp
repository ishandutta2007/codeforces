#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        int cur = m[i];
        int st = 0;
        while(true) {
            v[cur].PB(st);
            if (cur == 0) {
                break;
            }
            cur /= 2;
            ++st;
        }
    }
    ll ans = inf;
    for (int i = 0; i < max_n; ++i) {
        if (v[i].size() < k) {
            continue;
        }
        sort(v[i].begin(), v[i].end());
        ll sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += v[i][j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;


    return 0;
}