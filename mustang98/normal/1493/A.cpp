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
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        for (int i = k + 1; i <= n; ++i) {
            ans.PB(i);
        }
        for (int i = (k + 1) / 2; i < k; ++i) {
            ans.PB(i);
        }
        cout << ans.size() << endl;
        for (int a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }

    return 0;
}