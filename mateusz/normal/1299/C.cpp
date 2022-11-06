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

// #ifdef DEBUG
// #define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define debug(...) (__VA_ARGS__)
// #define cerr if(0)cout
// #endif

const int N = 1000005;

int n;
int tab[N];
long long value[N];
long long size[N];
int leftMost[N], rightMost[N], rep[N];
queue<pair<int, int> > Q;

int find(int w) {
    return rep[w] = (w == rep[w] ? w : find(rep[w]));
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        leftMost[i] = i;
        rightMost[i] = i;
        value[i] = tab[i];
        size[i] = 1;
        rep[i] = i;
        if (i > 1 && tab[i] < tab[i - 1]) {
            Q.push({-(i - 1), i});
        }
    }
    
    
    while (!Q.empty()) {/*
        cerr << -Q.front().first << " " << Q.front().second << endl;*/
        int w = find(-Q.front().first);
        int u = find(Q.front().second);
        Q.pop();
        if (w == u) continue;
//         cerr << w << " " << u << " " << value[w] << " " << size[w] << " " << value[u] << " " << size[u] << endl;
        long long newValue = (value[w] + value[u]);
        long long newSize = size[w] + size[u];
        leftMost[w] = min(leftMost[w], leftMost[u]);
        rightMost[w] = max(rightMost[w], rightMost[u]);
        rep[u] = w;
        value[w] = newValue;
        size[w] = newSize;
        int leftNeigh = find(leftMost[w] - 1);
        int rightNeigh = find(rightMost[w] + 1);
        if (leftNeigh > 0 && value[leftNeigh] * size[w] > value[w] * size[leftNeigh]) {
            Q.push({-leftNeigh, w});
        }
        if (rightNeigh > 0 && value[w] * size[rightNeigh] > value[rightNeigh] * size[w]) {
            Q.push({-w, rightNeigh});
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        printf("%.10Lf\n", (long double)value[find(i)] / size[find(i)]);
    }
    
    return 0;
}