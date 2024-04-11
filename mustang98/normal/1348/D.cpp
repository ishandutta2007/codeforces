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
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> ans;
        int sum = 1;
        ans.PB(1);
        int add = 1;
        while(true) {
            int x = n - sum;
            if (x > add * 2) {
                ans.PB(add * 2);
                add *= 2;
                sum += ans.back();
                continue;
            }
            if (x >= add) {
                ans.PB(x);
                sum += ans.back();
                break;
            }
            int s = ans.back() + x;
            ans.back() = s / 2;
            ans.push_back(s / 2 + s % 2);
            break;
        }
        cout << ans.size() - 1 << "\n";
        for (int i = 1; i < ans.size(); ++i) {
            cout << ans[i] - ans[i - 1] << ' ';
        }
        cout << "\n";
    }

    return 0;
}