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
char word[N];
int n, m, p;
clock_t timeStart;
vector<int> per;
int ans;
long long mask[N];
long long subMask;
vector<int> bestSubset;
vector<int> subset;
vector<int> elems[N];
int cnt[N];
unordered_set<long long> checkedGood, checkedBad;
bitset<N> contains[65];
bitset<N> current;
    
bool goodTime() {
    auto now = clock();
    return now - timeStart <= 2.8 * CLOCKS_PER_SEC;
}

bool bad() {
    return current.count() * 2 < n;
//     if (checkedGood.count(subMask)) return true;
//     if (checkedBad.count(subMask)) return false;
//     int cntGood = 0;
// //     debug(subMask);
//     for (int i = 0; i < n; i++) {
//         if ((mask[per[i]] & subMask) == subMask) {
//             cntGood++;
//         }
//         if ((cntGood + (n - 1 - i)) * 2 < n) {
//             checkedGood.insert(subMask);
//             return true;
//         }
//     }
// //     debug(cntGood);
//     if (2 * cntGood < n) {
//         checkedGood.insert(subMask);
//         return true;
//     }
//     checkedBad.insert(subMask);
//     return false;
}

void backtrack(int w, int k) {
    if (!goodTime()) return;
    if (bad()) {
        return;
    }
    if (subset.size() > ans) {
        ans = max(ans, (int)subset.size());
        bestSubset = subset;
    }
    if (k == elems[w].size()) return;
    auto prev = current;
    backtrack(w, k + 1);
    subset.push_back(elems[w][k]);
    subMask ^= (1LL << elems[w][k]);
    current &= contains[elems[w][k]];
    backtrack(w, k + 1);
    subMask ^= (1LL << elems[w][k]);
    subset.pop_back();
    current = prev;
}

int main() {
    timeStart = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d %d %d", &n, &m, &p);
    
    for (int i = 1; i <= n; i++) {
        scanf("%s", &word[0]);
        for (int j = 0; j < m; j++) {
            if (word[j] == '1') {
                mask[i] |= (1LL << j);
                contains[j].set(i);
                cnt[j]++;
                elems[i].push_back(j);
            }
        }
    }
    current.set();
    
    for (int i = 1; i <= n; i++) {
        for (int j = elems[i].size() - 1; j >= 0; j--) {
            if (cnt[elems[i][j]] * 2 < n) {
                swap(elems[i][j], elems[i].back());
                elems[i].pop_back();
            }
        }
        per.push_back(i);
    }
    
    shuffle(per.begin(), per.end(), rng);
    
    for (int w : per) {
        if (!goodTime()) {
            break;
        }
        shuffle(elems[w].begin(), elems[w].end(), rng);
        backtrack(w, 0);
    }
    
    vector<int> ansMask(m);
    for (int x : bestSubset) ansMask[x] = 1;
    for (int x : ansMask) printf("%d", x);
    printf("\n");
    
    return 0;
}