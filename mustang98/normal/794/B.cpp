#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, h;
    cin >> n >> h;
    ld curs = 0.5 * h * 100;
    ld curh = h;
    vector<ld> ans;
    ld needs = curs / n;
    for (int i = 0; i < n - 1; ++i) {
        ld hnew = sqrt(curh * curh * (curs - needs) / curs);
        ans.PB(hnew);
        curh = hnew;
        curs -= needs;
    }
    reverse(ans.begin(), ans.end());
    for (ld newh : ans) {
        std::cout << fixed << setprecision(8) << (newh) << "\n";
    }
    return 0;
}