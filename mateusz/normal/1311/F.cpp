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

long long tree[2 * BASE + 5];
int cnt[2 * BASE + 5];

int n;
int x[N], v[N], t[N];

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] += w;
        cnt[pos]++;
        pos /= 2;
    }
}

pair<long long, int> query(int posa, int posb) {
    if (posa > posb) {
        return {0, 0};
    }
    posa += BASE;
    posb += BASE;
    long long s = 0;
    int c = 0;
    s += tree[posa];
    c += cnt[posa];
    if (posa != posb) {
        s += tree[posb];
        c += cnt[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            s += tree[posa + 1];
            c += cnt[posa + 1];
        }
        if (posb % 2 == 1) {
            s += tree[posb - 1];
            c += cnt[posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return {s, c};
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        t[i] = i;
    }
    
    vector<pair<int, int> > events;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        events.push_back({v[i], i});
    }
    
    sort(events.begin(), events.end());
    
    int id = 0;
    for (int i = 0; i < events.size(); i++) {
        if (i == 0 || events[i].first != events[i - 1].first) {
            ++id;
        }
        v[events[i].second] = id;
    }
    
    sort(t + 1, t + 1 + n, [&](int a, int b) {return x[a] < x[b];});
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int w = t[i];
        auto p = query(1, v[w]);
        ans += (long long)p.second * x[w] - p.first;
        insert(v[w], x[w]);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}