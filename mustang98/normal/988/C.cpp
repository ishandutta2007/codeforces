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

map<ll, pair<int, int> > m;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        vector<int> v;
        ll sum = 0;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            sum += a;
            v.PB(a);
        }
        for (int j = 0; j < k; ++j) {
            ll sum1 = sum - v[j];
            if (m.find(sum1) != m.end() && m[sum1].F != i) {
                cout << "YES" << endl;
                cout << m[sum1].F + 1 << ' ' << m[sum1].S + 1 << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            } else {
                m[sum1] = MP(i, j);
            }
        }
    }
    cout << "NO";
    return 0;
}