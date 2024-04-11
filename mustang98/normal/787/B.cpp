#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 311, inf = 65535;

int main()
{
    //freopen("lca.in", "r", stdin);
    //freopen("lca.out", "w", stdout);
    int n, k, m, a;
    set<int> s;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        s.clear();
        bool foundeqv = false;
        for (int j = 0; j < k; ++j) {
            cin >> a;
            if (s.count(-a)) {
                foundeqv = true;
            }
            s.insert(a);
        }
        if (foundeqv == false) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}