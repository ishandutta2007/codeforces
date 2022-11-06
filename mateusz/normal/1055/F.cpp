#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define LL long long

const int N = 1000005;

int n;
long long k, b;
vector<pair<int, LL> >V[N];
LL val[N];
int id[N];

void DFS(int w) {
    for (auto p : V[w]) {
        int u = p.first;
        LL kr = p.second;
        val[u] = val[w] ^ kr;
        DFS(u);
    }
}

long long solve() {

    long long acc = 0;
    for (int i = 61; i >= 0; i--) {
        acc *= 2;
        long long sum = 0;
        
        int ptr = 1;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt++;
            if (j == n || (val[j] >> i) != (val[j + 1] >> i)) {
                while (ptr <= n && ((val[id[ptr]] >> i) ^ acc) <= (val[j] >> i)) {
                    if (((val[id[ptr]] >> i) ^ acc) == (val[j] >> i)) sum += cnt;
                    ptr++;
                }
                cnt = 0;
            }
        }
        
        int neg = 0;
        if (sum < k) {
            acc++;
            k -= sum;
            neg = 1;
        }
        
        int last = 0;
        vector<int> ones;
        for (int j = 1; j <= n; j++) {
            if (((val[id[j]] >> i) % 2) ^ neg) {
                ones.push_back(id[j]);
            } else {
                id[++last] = id[j];
            }
            if (j == n || (val[id[j]] >> (i + 1)) != (val[id[j + 1]] >> (i + 1))) {
                for (int x : ones) {
                    id[++last] = x;
                }
                ones.clear();
            }
        }
    }
    return acc;
}

int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 2; i <= n; i++) {
        int par;
        scanf("%d %lld", &par, &b);
        V[par].push_back({i, b});
    }
    
    DFS(1);
    sort(val + 1, val + 1 + n);
    for (int i = 1; i <= n; i++) id[i] = i;
    long long res = solve();
    
    printf("%lld\n", res);
    return 0;
}