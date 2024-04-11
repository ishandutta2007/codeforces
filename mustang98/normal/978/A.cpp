#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

int m[max_n];
set<int> s;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (s.count(m[i]) == 0) {
            s.insert(m[i]);
            ans.PB(m[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }

    return 0;
}