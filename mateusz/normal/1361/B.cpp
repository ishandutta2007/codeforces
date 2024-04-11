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

const int N = 1000005, M = 1000000007;

int n, p, wyk[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) w -= M;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int power(int a, int k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}


map<int, int> numA, numB;
set<int> diffPoses;

void update(int pos) {
    if (numA[pos] == numB[pos]) diffPoses.erase(pos);
    else diffPoses.insert(pos);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &p);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wyk[i]);
        }
        if (p == 1) {
            printf("%d\n", n % 2);
            continue;
        }
        numA.clear();
        numB.clear();
        sort(wyk + 1, wyk + 1 + n);
        diffPoses.clear();
        diffPoses.insert(-1);
        for (int i = n; i >= 1; i--) {
            int w = wyk[i];
            int firstDiff = *(--diffPoses.end());
            if (firstDiff == -1 || numA[firstDiff] < numB[firstDiff]) {
                numA[w]++;
                update(w);
                int ptr = w;
                while (numA[ptr] == p) {
                    numA[ptr] = 0;
                    numA[ptr + 1]++;
                    update(ptr + 1);
                    update(ptr);
                    ptr++;
                }
            } else {
                numB[w]++;
                update(w);
                int ptr = w;
                while (numB[ptr] == p) {
                    numB[ptr] = 0;
                    numB[ptr + 1]++;
                    update(ptr);
                    update(ptr + 1);
                    ptr++;
                }
            }
        }
        
        int ansA = 0;
        for (auto par : numA) {
            debug(par.first, par.second);
            add(ansA, mul(power(p, par.first), par.second));
        }
        debug("**");
        int ansB = 0;
        for (auto par : numB) {
            debug(par.first, par.second);
            add(ansB, mul(power(p, par.first), par.second));
        }
        printf("%d\n", (ansA - ansB + M) % M);
    }
    
    return 0;
}