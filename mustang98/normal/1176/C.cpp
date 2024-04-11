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

vector<int> v[6];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 4) v[0].PB(i);
        if (a == 8) v[1].PB(i);
        if (a == 15) v[2].PB(i);
        if (a == 16) v[3].PB(i);
        if (a == 23) v[4].PB(i);
        if (a == 42) v[5].PB(i);
    }
    for (int i = 0; i < 6; ++i) {
        reverse(v[i].begin(), v[i].end());
    }
    int cnt= 0;
    while(true) {
        int lst = -1;
        for (int i = 0; i < 6; ++i) {
            while(v[i].size() && v[i].back() < lst) {
                v[i].pop_back();
            }
            if (v[i].empty()) {
                cout << (n - cnt * 6) << endl;
                return 0;
            }
            lst = v[i].back();
            v[i].pop_back();
        }
        ++cnt;
    }
    return 0;
}