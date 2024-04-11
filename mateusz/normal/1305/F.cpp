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

const int N = 200005;

int n;
long long tab[N];
bool bylEl[N];
bool bylo[1000005];
long long ans;

clock_t timeStart;

long long res(long long d) {
    if (d <= 1000000) {
        bylo[d] = true;
    }
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        long long w = tab[i];
        long long closest = (w / d) * d;
        long long bigger = (w / d + 1) * d;
        if (closest == 0) {
            ret += bigger - w;
            continue;
        }
        ret += min(w - closest, bigger - w);
        if (ret > ans) break;
    }
    debug("res", d, ret);
    return ret;
}

void check(long long v) {
    if (v == 1) return;
    debug("check", v);
    vector<long long> divs = {v};
    for (int i = 2; (long long)i * i <= v; i++) {
        if (v % i == 0) {
            divs.push_back(i);
            if ((long long)i * i < v) {
                divs.push_back(v / i);
            }
        }
    }
    
    random_shuffle(divs.begin(), divs.end());
    
    for (auto div : divs) {
        if (div <= 1000000 && bylo[div]) {
            continue;
        }
        if (clock() - (long double)timeStart >= 2.0 * CLOCKS_PER_SEC) {
            break;
        }
        ans = min(ans, res(div));
    }
}

int main() {
    srand(time(NULL));
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &tab[i]);
    }
    
    random_shuffle(tab + 1, tab + 1 + n);
    
    timeStart = clock();
    ans = n + 1;
    ans = res(2);
    for (int w = 1; w <= n; w++) {
        auto t = clock() - timeStart;
        if (t >= 2.0 * CLOCKS_PER_SEC) {
            break;
        }
        
        check(tab[w]);
        if (tab[w] > 2) {
            check(tab[w] - 1);
        }
        check(tab[w] + 1);
    }
    
    printf("%lld\n", ans);
    return 0;
}