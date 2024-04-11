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

const int N = 2005, INF = 1e9;

const char* digits[] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011" 
};

int n, k;

char word[N][15];
int sufMini[N], sufMaxi[N];

int getDist(int w, int digit) {
    int ret = 0;
    for (int i = 0; i < 7; i++) {
        if (word[w][i] == '1' && digits[digit][i] == '0') {
            return INF;
        }
        if (word[w][i] == '0' && digits[digit][i] == '1') {
            ret++;
        }
    }
    return ret;
}

int findMini(int w) {
    int ret = 1e9;
    for (int d = 0; d < 10; d++) {
        ret = min(ret, getDist(w, d));
    }
    return ret;
}

int findMaxi(int w) {
    int ret = 0;
    for (int i = 0; i < 7; i++) {
        if (word[w][i] == '0') {
            ret++;
        }
    }
    return ret;
}

int main() {
    
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &word[i][0]);
    }
    
    for (int i = n; i >= 1; i--) {
        int mini = findMini(i);
        int maxi = findMaxi(i);
        sufMini[i] = sufMini[i + 1] + mini;
        sufMaxi[i] = sufMaxi[i + 1] + maxi;
    }
    
    string ans;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int d = 9; d >= 0; d--) {
            int dist = getDist(i, d);
            if (dist == INF) {
                continue;
            }
            if (sufMaxi[i + 1] >= k - dist && sufMini[i + 1] <= k - dist) {
                found = true;
                ans += d + '0';
                k -= dist;
                break;
            }
        }
        if (!found) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n", ans.c_str());

    return 0;
}