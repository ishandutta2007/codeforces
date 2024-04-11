#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long

#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


int pot[10005];

const int D = 505, S = 5005;

bool vis[D][S];
int dist[D][S];
int d, s;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    scanf("%d %d", &d, &s);
    
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    vis[0][0] = true;
    while (!Q.empty()) {
        auto state = Q.front();
        Q.pop();
        int r = state.first;
        int sum = state.second;
        for (int i = 0; i < 10; i++) {
            int new_r = (10 * r + i) % d;
            int new_sum = sum + i;
            if (new_sum <= s && !vis[new_r][new_sum]) {
                vis[new_r][new_sum] = true;
                dist[new_r][new_sum] = dist[r][sum] + 1;
                Q.push({new_r, new_sum});
                debug(new_r, new_sum, i, r, sum, dist[new_r][new_sum]);
            }
        }
    }
    
    int sR = 0;
    int sS = s;
    
    pot[0] = 1;
    for (int j = 1; j <= 10000; j++) {
        pot[j] = pot[j - 1] * 10 % d;
    }
    
    if (!vis[sR][sS]) {
        printf("-1\n");
        return 0;
    }
    
    int dd = dist[sR][sS];
    debug(dd);
    vector<int> digits;
    for (int i = 0; i < dd; i++) {
        int start = (i == 0 ? 1 : 0);
        for (int j = start; j < 10; j++) {
            int newSR = (d + sR - j * pot[dd - i - 1] % d) % d;
            int newSS = sS - j;
            
            if (newSS < 0) continue;
            if (!vis[newSR][newSS]) continue;
            debug(j);
            debug(newSR, newSS);
            debug(dist[newSR][newSS]);
            if (vis[newSR][newSS] && dist[newSR][newSS] <= dd - i - 1) {
                digits.push_back(j);
                sR = newSR;
                sS = newSS;
                break;
            }
        }
    }
    
    for (int x : digits) {
        printf("%d", x);
    }
    
}