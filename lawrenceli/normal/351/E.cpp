#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>

using namespace std;

const int maxn = 2005;
const int maxm = 100100;

int n, a[maxn], num[maxn][2], dp[maxn];
vector<int> v[maxm];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
        v[a[i]].push_back(i);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) num[j][1]++;
            else if (a[i] > a[j]) num[i][0]++;
        }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += min(num[i][0], num[i][1]);

    cout << ans << '\n';
}