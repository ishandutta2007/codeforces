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

int n, m;

vector<pair<int, int> > o;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        o.PB(MP(l, r));
    }
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        bool em = true;
        for (int j = 0; j < n; ++j) {
            if (i >= o[j].F && i <= o[j].S) {
                em = 0;
            }
        }
        if (em) {
            ans.PB(i);
        }
    }
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << ' ';
    }


    return 0;
}