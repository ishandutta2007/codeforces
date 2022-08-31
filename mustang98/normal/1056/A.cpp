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

set<int> s[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            int b;
            cin >> b;
            s[i].insert(b);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= 100; ++i) {
        bool can = true;
        for (int j = 0; j < n; ++j) {
            if (s[j].find(i) == s[j].end()) {
                can = false;
                break;
            }
        }
        if (can) {
            ans.PB(i);
        }
    }
    //cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << ' ';
    }

    return 0;
}