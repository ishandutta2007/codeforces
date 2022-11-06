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

int L, R;
vector<pair<int, int> > V[105];

int main() {
    
    scanf("%d %d", &L, &R);
    
    R -= L - 1;
    vector<int> bits;
    int w = R;
    while (w >= 1) {
        bits.push_back(w % 2);
        w /= 2;
    }
    
    reverse(bits.begin(), bits.end());
    int last = 2;
    if ((R & (R - 1)) == 0) {
    
        last = 2;
        V[last].push_back({1, 1});
        for (int i = 1; i < bits.size(); i++) {
            last++;
            for (int j = 2; j < last; j++) {
                for (auto &p : V[j]) {
                    p.second *= 2;
                }
            }
            for (auto p : V[last - 1]) {
                V[last].push_back(p);
            }
            for (auto &p : V[last - 1]) {
                p.second--;
            }
            for (auto &p : V[last]) {
                p.second--;
            }
            V[last].push_back({last - 1, 1});
            if (bits[i] == 1) {
                last++;
                V[last].push_back({last - 1, 1});
                V[last].push_back({1, 1});
            }
        }

    } else {
        last = bits.size() + 2;
        int acc = 0;
        for (int i = 0; i < bits.size(); i++) {
            acc = 2 * acc + bits[i];
            if (i == 0) continue;
            if (bits[i] == 1) {
                int a = 1;
                int b = i + 2;
                int weight = (acc - 1) << (bits.size() - 1 - i);
                V[b].push_back({a, weight});
            }
        }
        V[last].push_back({1, 1});
        
        for (int i = 1; i < bits.size(); i++) {
            V[last].push_back({i + 2, 1});
            for (int j = i + 1; j < bits.size(); j++) {
                int a = i + 2;
                int b = j + 2;
                int weight = 1 << (bits.size() - 1 - j);
                V[b].push_back({a, weight});
            }
        }
        
        V[2].push_back({1, 1});
        for (int i = 1; i + 1 < bits.size(); i++) {
            int a = 2;
            int b = i + 2;
            int weight = (1 << (bits.size() - 1 - i)) - 1;
            V[b].push_back({a, weight});
        }
        V[last].push_back({2, 1});
    }
    if (L > 1) {
        for (auto &p : V[last]) {
            p.second += L - 1;
        }
    }
    int m = 0;
    for (int i = 2; i <= last; i++) {
        m += V[i].size();
    }
    
    printf("YES\n");
    printf("%d %d\n", last, m);
    for (int i = 2; i <= last; i++) {
        for (auto p : V[i]) {
            printf("%d %d %d\n", p.first, i, p.second);
        }
    }
    
    
    
    return 0;
}