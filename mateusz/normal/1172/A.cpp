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

const int N = 200005;

int n;
int inHand[N];
int pile[N];
bool removed[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &inHand[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pile[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (pile[i] == 1) {
            bool good = true;
            for (int j = i + 1; j <= n; j++) {
                good &= pile[j] == j - i + 1;
            }
            if (good) {
                int len = n - i + 1;
                bool canFinish = true;
                for (int j = 1; j < i; j++) {
                    if (pile[j] > 0) {
                        canFinish &= j < (pile[j] - len);
                    }
                }
                if (canFinish) {
                    printf("%d\n", n - len);
                    return 0;
                }
            }
        }
    }
    
    priority_queue<pair<int, int> > Q;
    for (int i = 1; i <= n; i++) {
        if (pile[i] > 0) {
            Q.push({i - pile[i], pile[i]});
        }
    }
    
    int moves = 0;
    for (int i = 0; i <= n; i++) {
        removed[pile[i]] = true;
        while (!Q.empty() && removed[Q.top().second]) {
            Q.pop();
        }
        if (Q.empty() || Q.top().first - i < 0) {
            moves = i;
            break;
        }
    }
    
    printf("%d\n", moves + n);
    
    return 0;
}