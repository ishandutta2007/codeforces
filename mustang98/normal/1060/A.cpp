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

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        int a = c - 48;
        if (a == 8) {
            a = -1;
        }
        v.PB(a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while (v.size() >= 11) {
        if (v[0] != -1) {
            break;
        }
        v.erase(v.begin());
        for (int i = 0; i < 10; ++i) {
            v.pop_back();
        }
        ++ans;
    }
    cout << ans;


    return 0;
}