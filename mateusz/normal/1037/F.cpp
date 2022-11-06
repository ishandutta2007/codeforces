#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, M = 1000000007;

int n, k;
int tab[N];
int firstLeft[N], firstRight[N];
long long prefSum[N];

int main() {
    
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    vector<int> s;
    tab[0] = 2e9;
    tab[n + 1] = 2e9;
    s.push_back(0);
    
    for (int i = 1; i <= n; i++) {
        while (tab[s.back()] < tab[i]) {
            s.pop_back();
        }
        firstLeft[i] = s.back();
        s.push_back(i);
    }
    
    s.clear();
    s.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (tab[s.back()] <= tab[i]) {
            s.pop_back();
        }
        firstRight[i] = s.back();
        s.push_back(i);
    }
    
    prefSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefSum[i] = prefSum[i - 1] + i / (k - 1);
        if (prefSum[i] >= M) prefSum[i] -= M;
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
//         cerr << "elo " << i << " " << firstLeft[i] << " " << firstRight[i] << endl;
        int x = i - firstLeft[i];
        int y = firstRight[i] - i - 1;
//         cerr << x << " " << y << endl;
//         long long tmp = 0;
        int firstValAdd = y;
        int lastValAdd = y + x - 1;
//         int firstValSubtract = 0;
        int lastValSubtract = max(0, x - 2);
//         for (int j = 1; j <= x; j++) {
//             tmp += (j + y - 1) / (k - 1);
//             tmp -= max(0, (j - 1 - 1)) / (k - 1);
//         }
        if (firstValAdd == 0) firstValAdd++;
        long long tmp = (prefSum[lastValAdd] - prefSum[firstValAdd - 1] - prefSum[lastValSubtract] + 2 * M) % M;
        ans += (long long)tab[i] * tmp % M;
        ans %= M;
//         cerr << i << " " << tmp << endl;
    }
    
    printf("%lld\n", ans);
    
   
    return 0;
}