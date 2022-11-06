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

const int N = 100005;

int a, b, c;

int dist(int a, int b, int c, int A, int B, int C) {
    return abs(A - a) + abs(B - b) + abs(C - c);
}

void test() {
    scanf("%d %d %d", &a, &b, &c);
    int ans = 1e9;
    int bestA = a, bestB = b, bestC = c;
    for (int A = 1; A <= 10000; A++) {
        for (int B = A; B <= 20000; B += A) {
            int C = B * (c / B);
            if (C == 0) C = B;
            if (dist(a, b, c, A, B, C) < ans) {
                ans = dist(a, b, c, A, B, C);
                bestA = A;
                bestB = B;
                bestC = C;
            }
            C = B * (c / B + 1);
            if (dist(a, b, c, A, B, C) < ans) {
                ans = dist(a, b, c, A, B, C);
                bestA = A;
                bestB = B;
                bestC = C;
            }
        }
    }
    printf("%d\n", ans);
    printf("%d %d %d\n", bestA, bestB, bestC);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}