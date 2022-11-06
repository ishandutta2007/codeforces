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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int n, col[5005];
int cnt[5005], ans[5005];

int main() {
    string line;
    cin >> line;
    
    string left,right;
    bool wasDw = false;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ':') wasDw = true;
        if (wasDw) right += line[i];
        else left += line[i];
    }
    
    map<char, int> dig;
    for (char i = '0'; i <= '9'; i++) {
        dig[i] = i - '0';
    }
    
    for (int i = 'A'; i <= 'Z'; i++) {
        dig[i] = i - 'A' + 10;
    }
    
    
    vector<int> goodBases;
    for (int base = 1; base <= 65; base++) {
        int hour = 0;
        bool bad = false;
        for (char c : left) {
            debug(c, dig[c]);
            hour = base * hour + dig[c];
            if (dig[c] >= base || hour >= 24) {
                bad = true;
            }
        }
        debug(hour);
        int  minute = 0;
        for (char c : right) {
            minute = base * minute + dig[c];
            if (dig[c] >= base || minute >= 60) {
                bad = true;
            }
        }
        if (bad) continue;
        goodBases.push_back(base);
    }
    
    if (!goodBases.empty() && goodBases.back() == 65) {
        printf("-1\n");
    } else {
        if (goodBases.empty()) {
            printf("0\n");
            return 0;
        }
        for (auto c : goodBases) {
            printf("%d ", c);
        }
        printf("\n");
    }
    
    return 0;
}