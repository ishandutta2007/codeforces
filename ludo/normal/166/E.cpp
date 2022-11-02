#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int n;

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif // LOCAL

    cin >> n;
    ll cnt[4] = { 1 }, nextcnt[4] = {};
    for (int i = 0; i < n; i++) {
        nextcnt[0] = (cnt[1] + cnt[2] + cnt[3]) % MOD;
        nextcnt[1] = (cnt[0] + cnt[2] + cnt[3]) % MOD;
        nextcnt[2] = (cnt[0] + cnt[1] + cnt[3]) % MOD;
        nextcnt[3] = (cnt[0] + cnt[1] + cnt[2]) % MOD;
        cnt[0] = nextcnt[0];
        cnt[1] = nextcnt[1];
        cnt[2] = nextcnt[2];
        cnt[3] = nextcnt[3];
    }
    cout << cnt[0] << endl;
    return 0;
}