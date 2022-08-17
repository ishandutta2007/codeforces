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

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> res;
        for (int i = 0; i < 5; ++i) {
            res.push_back(n % 10);
            n /= 10;
        }
        vector<int> res1;
        int m = 1;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == 0) {
                m *= 10;
                continue;
            }
            res1.push_back(res[i] * m);
            m *= 10;
            continue;
        }
        cout << res1.size() << "\n";
        for (int a : res1) {
            cout << a << ' ';
        }
        cout << "\n";
    }
    return 0;
}