#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> v;
vector<int> v1;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    sort(v.begin(), v.end());
    int cur1 = 0, cur2 = 0;
    int ans = 0;
    while(cur2 < n) {
        if (v[cur2] > v[cur1]) {
            ans++;
            cur1++;
            cur2++;
        } else {
            cur2++;
        }
    }
    cout << ans;
    return 0;
}