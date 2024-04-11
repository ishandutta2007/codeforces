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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

long double dist(long double xA, long double yA, long double xB, long double yB) {
    long double dx = xA - xB;
    long double dy = yA - yB;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    long long A, B, C, xA, yA, xB, yB;
    cin >> A >> B >> C;
    cin >> xA >> yA >> xB >> yB;
    
    long double ans = abs(xA - xB) + abs(yA - yB);
    if (A == 0 || B == 0) {
        cout << abs(xA - xB) + abs(yA - yB) << endl;
        return 0;
    }
    long double yyA = (-C - (long double)A * xA) / B;
    long double yyB = (-C - (long double)A * xB) / B;
    ans = min(ans, fabs(yA - yyA) + fabs(yB - yyB) + dist(xA, yyA, xB, yyB));
    
    long double xxA = (-C - (long double)B * yA) / A;
    long double xxB = (-C - (long double)B * yB) / A;
    ans = min(ans, fabs(xA - xxA) + fabs(xB - xxB) + dist(xxA, yA, xxB, yB));
    
    ans = min(ans, fabs(xA - xxA) + fabs(yB - yyB) + dist(xxA, yA, xB, yyB));
    ans = min(ans, fabs(yA - yyA) + fabs(xB - xxB) + dist(xA, yyA, xxB, yB));
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}