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

vector<int> v[max_n];

int n;
int depth[max_n];
int cntd[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    depth[0] = 0;
    cntd[0] = 1;
    for (int i = 1; i < n; ++i) {
        int pr;
        cin >> pr;
        pr--;
        depth[i] = depth[pr] + 1;
        cntd[depth[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < max_n; ++i) {
        ans += cntd[i] % 2;
    }
    cout << ans;
    return 0;
}