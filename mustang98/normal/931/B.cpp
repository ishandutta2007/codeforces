#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        v.PB(i);
    }
    int cur = 1;
    while (true) {
        vector<int> v1;
        for (int i = 0; i < v.size(); i += 2) {
            if (v[i] == a && v[i + 1] == b) {
                if (v.size() == 2) cout << "Final!";
                else cout << cur << endl;
                return 0;
            }
            if (v[i + 1] == a || v[i + 1] == b) {
                v1.PB(v[i + 1]);
            } else {
                v1.PB(v[i]);
            }
        }
        v = v1;
        ++cur;
    }
    return 0;
}