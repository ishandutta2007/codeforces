#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

int mod = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<long long> prev(4), cur(4);
    prev[0] = 1;
    prev[1] = prev[2] = prev[3] = 0;
    for(int i = 1; i <= n; ++i) {
            cur[0] = (prev[1] + prev[2] + prev[3]) % mod;
            cur[1] = (prev[0] + prev[2] + prev[3]) % mod;
            cur[2] = (prev[0] + prev[1] + prev[3]) % mod;
            cur[3] = (prev[0] + prev[1] + prev[2]) % mod;
            prev = cur;
    }
    cout << prev[0];
    cin >> n;
    return 0;
}