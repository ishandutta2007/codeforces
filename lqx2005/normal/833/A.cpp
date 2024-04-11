#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N = 1e6 + 10;
int n, vis[N], p[N], pri[N], tot = 0; 
vector<int> fac[N];
void sieve(int n) {
    vis[0] = vis[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) p[++tot] = i, pri[i] = i, fac[i].pb(i);
        for(int j = 1; j <= tot && i * p[j] <= n; j++) {
            vis[i * p[j]] = 1;
            pri[i * p[j]] = p[j];
            fac[i * p[j]] = fac[i];
            if(i % p[j] == 0) break;
            fac[i * p[j]].pb(p[j]);
        }
    }
    return;
}
int main() {
    sieve(N - 10);
    int n;
    for(cin >> n; n--; ) {
        int a, b;
        scanf("%d%d", &a, &b);
        ll c = 1ll * a * b;
        int d = floor(pow(c, 1.0 / 3));
        while(1ll * (d + 1) * (d + 1) * (d + 1) <= c) d++;
        if(c != 1ll * d * d * d) {
        	puts("No");
            continue;
        }
        vector<int> tmp = fac[d];
        int flag = 1;
        for(int p : tmp) {
            int ca = 0, cb = 0;
            for(; a % p == 0; a /= p, ca++);
            for(; b % p == 0; b /= p, cb++);
            if(ca > cb) swap(ca, cb);
            if(ca * 2 < cb) {
                flag = 0;
                break;
            }
        }
        if(!flag) puts("No");
        else puts("Yes");
    }
	return 0;
}