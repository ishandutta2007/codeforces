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

const int N = 200005, LOG = 18;

int n, tab[N], t[N];
int nextSmaller[N], nextGreater[N];
int rmqMax[LOG + 2][N], rmqMin[LOG + 2][N];
int val[N];
int pot[N];

int queryMax(int from, int to) {
    int l = to - from + 1;
    int P = pot[l];
    return max(rmqMax[P][from], rmqMax[P][to - (1 << P) + 1]);
}

int queryMin(int from, int to) {
    int l = to - from + 1;
    int P = pot[l];
    return min(rmqMin[P][from], rmqMin[P][to - (1 << P) + 1]);
}

int main() {
    
    scanf("%d", &n);
    
    pot[1] = 0;
    for (int i = 2; i <= 2 * n; i++) {
        pot[i] = pot[i / 2] + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        tab[i + n] = tab[i];
    }
    
    for (int i = 1; i <=  2 * n; i++) {
        rmqMin[0][i] = tab[i];
        rmqMax[0][i] = tab[i];
    }
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i + (1 << (l - 1)) <= 2 * n; i++) {
            rmqMin[l][i] = min(rmqMin[l - 1][i], rmqMin[l - 1][i + (1 << (l - 1))]);
            rmqMax[l][i] = max(rmqMax[l - 1][i], rmqMax[l - 1][i + (1 << (l - 1))]);
        }
    }
    
    debug(queryMin(5, 7));
    for (int i = n; i >= 1; i--) {
        int low = 1;
        int high = n;
        int res = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            debug(i, mid, queryMin(i + 1, i + mid), tab[i]);
            if (queryMin(i + 1, i + mid) * 2 < tab[i]) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        debug(i, res);
        nextSmaller[i] = (i + res - 1) % n + 1;
    }
    
    for (int i = n; i >= 1; i--) {
        int low = 1;
        int high = n;
        int res = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (queryMax(i + 1, i + mid) > tab[i]) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        nextGreater[i] = (i + res - 1) % n + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        t[i] = i;
        debug(i, nextSmaller[i], nextGreater[i]);
    }
    sort(t + 1, t + 1 + n, [](int a, int b) { return tab[a] < tab[b]; });
    
    for (int i = n; i >= 1; i--) {
        int w = t[i];
        int smallerDist = nextSmaller[w] - w;
        if (smallerDist < 0) smallerDist += n;
        if (smallerDist == 0) smallerDist = 1e9;
               
        int greaterDist = nextGreater[w] - w;
        if (greaterDist < 0) greaterDist += n;
        int greaterVal = greaterDist + val[nextGreater[w]];
        if (nextGreater[w] == w) {
            greaterVal = 1e9;
        }
        val[w] = min(smallerDist, greaterVal);
    }
    
    
    for (int i = 1; i <= n; i++) {
        if (val[i] < 1e9) {
            printf("%d ", val[i]);
        } else {
            printf("%d ", -1);
        }
    }
    printf("\n");
    
    return 0;
}