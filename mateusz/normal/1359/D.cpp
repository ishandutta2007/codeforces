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

const int N = 100005, BASE = 131072;

int prefTree[2 * BASE + 5], sufTree[2 * BASE + 5];
int n, a[N];
int prefSum[N], sufSum[N];
int firstLeft[N], firstRight[N];

void insert(int *tree, int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int query(int *tree, int posa, int posb) {
    posa += BASE;
    posb += BASE;
    if (posa > posb) {
        return 0;
    }
    int ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int main() {
    
    scanf("%d", &n);
    
    vector<int> s;
    s.push_back(0);
    a[0] = 50;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        prefSum[i] = prefSum[i - 1] + a[i];
        while (a[s.back()] <= a[i]) {
            s.pop_back();
        }
        firstLeft[i] = s.back();
        s.push_back(i);
    }
    
    s.clear();
    s.push_back(n + 1);
    a[n + 1] = 50;
    for (int i = n; i >= 1; i--) {
        sufSum[i] = sufSum[i + 1] + a[i];
        while (a[s.back()] <= a[i]) {
            s.pop_back();
        }
        firstRight[i] = s.back();
        s.push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        insert(prefTree, i, prefSum[i]);
        insert(sufTree, i, sufSum[i]);
    }
    
    int totalSum = prefSum[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, totalSum - query(prefTree, firstLeft[i], i - 1) - query(sufTree, i + 1, firstRight[i]) - a[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}