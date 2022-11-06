#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 200005, BASE = (1 << 18);

long long tree[2 * BASE + 5], W[2 * BASE + 5];;
int n, m, p, weapon[N], costWeapon[N], armor[N], armorCost[N], monDef[N], monAtt[N], monCoins[N];
int t[N];

void insert(int posa, int posb, int w) {
    if (posa > posb) return;
    posa += BASE;
    posb += BASE;
    tree[posa] += w;
    W[posa] += w;
    if (posa != posb) {
        tree[posb] += w;
        W[posb] += w;
    }
    while (posa >= 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                tree[posa + 1] += w;
                W[posa + 1] += w;
            }
            if (posb % 2 == 1) {
                tree[posb - 1] += w;
                W[posb - 1] += w;
            }
        }
        posa /= 2;
        posb /= 2;
        W[posa] = max(W[posa * 2], W[posa * 2 + 1]) + tree[posa];
        W[posb] = max(W[posb * 2], W[posb * 2 + 1]) + tree[posb];
    }
}

int main() {
    
    scanf("%d %d %d", &n, &m, &p);
    
    vector<pair<pair<int, int>, int> >  events;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weapon[i], &costWeapon[i]);
        events.push_back({{weapon[i], -1}, costWeapon[i]});
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &armor[i], &armorCost[i]);
        t[i] = i;
    }
    
    sort(t + 1, t + 1 + m, [&](int a, int b) { return armor[a] < armor[b]; });
    
    for (int i = 1; i <= 2 * BASE; i++) {
        W[i] = -1e9;
    }
    
    for (int i = 1; i <= m; i++) {
        tree[i + BASE] = W[i + BASE] = -armorCost[t[i]];
    }
    for (int i = BASE - 1; i >= 1; i--) {
        W[i] = max(W[2 * i], W[2 * i + 1]);
    }
    
    for (int i = 1; i <= p; i++) {
        scanf("%d %d %d", &monDef[i], &monAtt[i], &monCoins[i]);
        events.push_back({{monDef[i], monAtt[i]}, monCoins[i]});
    }
    
    sort(events.begin(), events.end());
    
    long long ans = -1e18;
    for (auto event : events) {
        int x = event.first.first;
        int y = event.first.second;
        int coins = event.second;
        if (y == -1) { // Weapon
            debug("weapon", x, coins, tree[1]);
            ans = max(ans, W[1] - coins);
        } else {
            int low = 1;
            int high = m;
            int res = m + 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (armor[t[mid]] > y) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            debug("monster ", x, y, coins, res);
            insert(res, m, coins);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}