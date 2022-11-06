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

const int BASE = (1 << 19), N = 200005;

int n, q, from[N], to[N];
char S[N], T[N];
int W[4 * BASE + 5], w[4 * BASE + 5], Size[2 * BASE + 5];

void insert(int posa, int posb, int c) {
//     cerr << "insert " << posa << " " << posb << " " << c << endl;
    posa += BASE;
    posb += BASE;
    w[posa] += c;
    W[posa] += c;
    if (posa != posb) {
        w[posb] += c;
        W[posb] += c;
    }
    while (posa >= 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                w[posa + 1] += c;
                W[posa + 1] = W[2 * (posa + 1)] + W[2 * (posa + 1) + 1] + Size[posa + 1] * w[posa + 1];
            }
            if (posb % 2 == 1) {
                w[posb - 1] += c;
                W[posb - 1] = W[2 * (posb - 1)] + W[2 * (posb - 1) + 1] + Size[posb - 1] * w[posb - 1];
            }
        }
        posa /= 2;
        posb /= 2;
        W[posa] = W[posa * 2] + W[posa * 2 + 1] + Size[posa] * w[posa];
        W[posb] = W[posb * 2] + W[posb * 2 + 1] + Size[posb] * w[posb];
    }
}

int query(int posa, int posb) {
//     cerr << "query " << posa << " " << posb << endl;
    posa += BASE;
    posb += BASE;
    int ret = W[posa];
    int affA = 1;
    int affB = 0;
    if (posa != posb) {
        ret += W[posb];
        affB++;
    }
    while (posa >= 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                ret += W[posa + 1];
                affA += Size[posa + 1];
            }
            if (posb % 2 == 1) {
                ret += W[posb - 1];
                affB += Size[posb - 1];
            }
        }
        posa /= 2;
        posb /= 2;
        ret += w[posa] * affA;
        ret += w[posb] * affB;
    }
//     cerr << "ret = " << ret << endl;
    return ret;
}

int main() {
    
    for (int i = BASE; i < 2 * BASE; i++) {
        Size[i] = 1;
    }
    for (int i = BASE - 1; i >= 1; i--) {
        Size[i] = Size[2 * i] + Size[2 * i + 1];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        scanf("%s %s", &S[1], &T[1]);
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &from[i], &to[i]);
        }
        
        set<pair<int, int>> intervals;
        for (int i = 1; i <= n; i++) {
            S[i] -= '0';
            T[i] -= '0';
            if (T[i]) {
                intervals.insert({i, i});
                insert(i, i, 1);
            }
        }
        
        bool bad = false;
        for (int i = q; i >= 1; i--) {
            int len = to[i] - from[i] + 1;
            int ones = query(from[i], to[i]);
            if (ones * 2 == len) {
//                 debug("failed", i);
                bad = true;
                break;
            }
            auto it = intervals.lower_bound({from[i], -1e9});
            vector<pair<int, int> > toRestore;
            while (it != intervals.end()) {
                int intFrom = it->second;
                int intTo = it->first;
                if (intFrom > to[i]) {
                    break;
                }
                if (intFrom < from[i]) {
                    toRestore.push_back({intFrom, from[i] - 1});
                }
                if (intTo > to[i]) {
                    toRestore.push_back({to[i] + 1, intTo});
                }
                auto it2 = it;
                ++it;
                insert(intFrom, intTo, -1);
                intervals.erase(it2);
            }
            for (auto p : toRestore) {
                intervals.insert({p.second, p.first});
                insert(p.first, p.second, 1);
            }
            if (2 * ones > len) {
                intervals.insert({to[i], from[i]});
                insert(from[i], to[i], 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (query(i, i) != S[i]) {
                bad = true;
                break;
            }
        }
        for (auto p : intervals) {
            insert(p.second, p.first, -1);
        }
        printf(bad ? "NO\n" : "YES\n");
    }
    
    return 0;
}