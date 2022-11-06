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

const int N = 200005;

int n, k;
char word[N];
bool isSpecial[N];
int myLastSpecial[N], myNextSpecial[N];

int mod(int w) {
    if (w < 0) {
        return w + n;
    }
    if (w >= n) {
        return w - n;
    }
    return w;
}


int main() {
    
    scanf("%d %d", &n, &k);
    
    scanf("%s", &word[0]);
    
    for (int i = 0; i < n; i++) {
        word[i] = word[i] == 'B' ? 1 : 0;
    }
    
    int lastSpecial = -1;
    for (int i = 0; i < 2 * n - 1; i++) {
        debug(i, mod(i), mod(i - 1), mod(i + 1), word[mod(i - 1)], word[mod(i)], word[mod(i + 1)]);
        if (word[mod(i)] == word[mod(i - 1)] || word[mod(i)] == word[mod(i + 1)]) {
            isSpecial[mod(i)] = true;
            lastSpecial = mod(i);
        } else {
            myLastSpecial[mod(i)] = lastSpecial;
        }
    }
    
    int nextSpecial = -1;
    for (int i = 2 * n - 2; i >= 0; i--) {
        if (word[mod(i)] == word[mod(i - 1)] || word[mod(i)] == word[mod(i + 1)]) {
            isSpecial[mod(i)] = true;
            nextSpecial = mod(i);
        } else {
            myNextSpecial[mod(i)] = nextSpecial;
        }
    }
    
    for (int i = 0; i < n; i++) {
        debug(i, isSpecial[i]);
        if (isSpecial[i]) {
            printf(word[i] ? "B" : "W");
            continue;
        }
        if (myLastSpecial[i] == -1) {
            printf((word[i] + k) % 2 ? "B" : "W");
            continue;
        }
        debug(i, mod(i - myLastSpecial[i]), mod(myNextSpecial[i] - i));
        if (mod(i - myLastSpecial[i]) <= mod(myNextSpecial[i] - i)) {
            if (mod(i - myLastSpecial[i]) <= k) {
                printf(word[myLastSpecial[i]] ? "B" : "W");
            } else {
                printf((word[i] + k) % 2 ? "B" : "W");
            }
        } else {
            if (mod(myNextSpecial[i] - i) <= k) {
                printf(word[myNextSpecial[i]] ? "B" : "W");
            } else {
                printf((word[i] + k) % 2 ? "B" : "W");
            }
        }
    }
    printf("\n");
    
    return 0;
}