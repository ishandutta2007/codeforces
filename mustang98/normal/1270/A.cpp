#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

vector<int> v1, v2;
int n;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        v1.clear();
        v2.clear();
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        for (int i = 0; i < k1; ++i) {
            int a;
            cin >> a;
            v1.PB(a);
        }
        for (int i = 0; i < k2; ++i) {
            int a;
            cin >> a;
            v2.PB(a);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1.back() > v2.back()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}