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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

int n, A[N];

int getCost(int mid) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        int first = A[i] == -1 ? mid : A[i];
        int second = A[i + 1] == -1 ? mid : A[i + 1];
        ret = max(ret, abs(first - second));
    }
    return ret;
}

int getCostUp(int mid) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        int first = A[i] == -1 ? mid : A[i];
        int second = A[i + 1] == -1 ? mid : A[i + 1];
        if (A[i] == -1 && A[i + 1] == -1) continue;
        if ((first < second && A[i] == -1) || (first > second && A[i + 1] == -1)) {
            ret = max(ret, abs(first - second));
        }
    }
    return ret;
}

int getCostDown(int mid) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        int first = A[i] == -1 ? mid : A[i];
        int second = A[i + 1] == -1 ? mid : A[i + 1];
        if (A[i] == -1 && A[i + 1] == -1) continue;
        if ((first < second && A[i + 1] == -1) || (first > second && A[i] == -1)) {
            ret = max(ret, abs(first - second));
        }
    }
    return ret;
}

void test() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    
    int low = 0;
    int high = 1e9;
    int bestCost = 2e9;
    int best = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int costUp = getCostUp(mid);
        int costDown = getCostDown(mid);
        int cost = getCost(mid);
        if (cost < bestCost) {
            best = mid;
            bestCost = cost;
        }
        if (costUp > costDown) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d %d\n", bestCost, best);
}

int main() {
    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        test();
    }
    
    return 0;
}