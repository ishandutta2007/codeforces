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

int n;
char word[N];
int cnt[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", &word[0]);
        bool theSame = true;
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) {
                theSame = false;
                break;
            }
        }
        if (theSame) {
            printf("%d\n", (n + 2) / 3);
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (word[i] == 'L') {
                cnt[(i - 1 + n) % n]++;
            } else {
                cnt[(i + 1) % n]++;
            }
        }
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                Q.push(i);
            }
        }
        int ans = 0;
        while (!Q.empty()) {
            int w = Q.front();
            Q.pop();
            int prev = -1;
            int steps = 0;
            while (true) {
                int newPrev = w;
                steps++;
                if (word[w] == 'R') {
                    w++;
                    if (w >= n) w -= n;
                } else {
                    w--;
                    if (w < 0) w += n;
                }
                if (w == prev) {
                    break;
                }
                prev = newPrev;
            }
            steps -= 2;
            if (steps % 3 <= 1) {
                ans += steps / 3;
            } else {
                ans += steps / 3 + 1;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}