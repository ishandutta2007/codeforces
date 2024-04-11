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

int m[max_n];
int n;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int allsum = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        allsum += m[i];
    }
    int sum = m[0];
    ans.PB(0);
    for (int i = 1; i < n; ++i) {
        if (m[0] >= m[i] * 2) {
            sum += m[i];
            ans.PB(i);
        }
    }
    if (sum * 2 <= allsum) {
        cout << 0 << endl;
    } else {
        cout << ans.size() << endl;
        for (int a : ans) {
            cout << a + 1 << ' ';
        }
    }

    return 0;
}