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

const int N = 3005;

int n, k;
char word[N];

int main() {
    
    scanf("%d %d", &n, &k);
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        word[i] = (word[i] == 'R');
    }
    
    vector<vector<int> > optimal;
    while (true) {
        vector<int> newStep;
        for (int i = 1; i < n; i++) {
            if (word[i] > word[i + 1]) {
                newStep.push_back(i);
                swap(word[i], word[i + 1]);
                i++;
                continue;
            }
        }
        if (newStep.empty()) {
            break;
        }
        optimal.push_back(newStep);
    }
    
    int maxPossible = 0;
    for (auto &x : optimal) {
        maxPossible += x.size();
    }
    
    if (optimal.size() > k) {
        printf("-1\n");
        return 0;
    }
    
    int initK = k;
    
    vector<vector<int>> actual;
    for (int i = 0; i < optimal.size(); i++) {
        if (k - 1 <= maxPossible - (int)optimal[i].size()) {
            actual.push_back(optimal[i]);
            k--;
            maxPossible -= optimal[i].size();
            continue;
        }
        
        vector<int> thisStep;
        int ptr = 0;
        while (ptr < optimal[i].size() && maxPossible > k - 1) {
            thisStep.push_back(optimal[i][ptr++]);
            maxPossible--;
        }
        if (thisStep.empty()) {
            printf("-1\n");
            return 0;
        }
        k--;
        actual.push_back(thisStep);
        for (int j = ptr; j < optimal[i].size(); j++) {
            actual.push_back({optimal[i][j]});
        }
        for (int j = i + 1; j < optimal.size(); j++) {
            for (int x : optimal[j]) {
                actual.push_back({x});
            }
        }
        break;
    }
    
    if (actual.size() != initK) {
        printf("-1\n");
        return 0;
    }
    
    for (auto v : actual) {
        printf("%d ", v.size());
        for (int x : v) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    
    return 0;
}