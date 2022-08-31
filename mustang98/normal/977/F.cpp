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

vector<int> v;
map<int, int> d;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v.PB(a);
    }
    int max_v = -1;
    int max_c = -1;
    for (int i = 0; i < n; ++i) {
        int c = v[i];
        d[c] = 1;
        if (d.find(c - 1) != d.end()) {
            d[c] = d[c - 1] + 1;
        }
        if (d[c] > max_v) {
            max_v = d[c];
            max_c = c;
        }
    }
    vector<int> ans;
    reverse(v.begin(), v.end());
    int cur = max_c;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == cur) {
            ans.PB(n - i);
            cur--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}