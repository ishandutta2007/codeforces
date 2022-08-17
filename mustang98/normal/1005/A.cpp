#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1001, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> ans;
    int n;
    cin >> n;
    int cnt = 1;
    int a;
    cin >> a;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ans.PB(cnt);
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    ans.PB(cnt);
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << ' ';
    }

    return 0;
}