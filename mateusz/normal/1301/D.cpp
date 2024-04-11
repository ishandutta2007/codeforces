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

const int N = 505;

int n, m, k;

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    const int tochar[] = {'R', 'L', 'D', 'U'};
    
    vector<pair<int, int> > instr;
    for (int i = 1; i <= n; i++) {
        instr.push_back({0, m - 1});
        if (i < n) {
            instr.push_back({1, m - 1});
            instr.push_back({2, 1});
        }
    }
    for (int i = m; i >= 1; i--) {
        instr.push_back({3, n - 1});
        if (i > 1) {
            instr.push_back({2, n - 1});
            instr.push_back({1, 1});
        }
    }
    
   
    
    vector<pair<int, int> > realInstr;
    int rest = k;
    for (int i = 0; i < instr.size(); i++) {
        int dir = instr[i].first;
        int steps = instr[i].second;
        if (steps == 0) continue;
        if (steps >= rest) {
            realInstr.push_back({dir, rest});
            rest = 0;
            break;
        }
        realInstr.push_back(instr[i]);
        rest -= steps;
    }
    
    if (rest > 0) {
        printf("NO\n");
        return 0;
    }
    
    printf("YES\n");
    printf("%d\n", realInstr.size());
    for (auto p : realInstr) {
        printf("%d %c\n", p.second, tochar[p.first]);
    }
    
    return 0;
}