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

int t, n;
char word[N];
int marked[N];

void test() {
    scanf("%d", &n);
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        word[i] -= '0';
    }
    for (int d = -1; d <= 9; d++) {
        bool failed = false;
        vector<int> lower, greater;
        for (int i = 1; i <= n; i++) {
            if (word[i] <= d) {
                if (!lower.empty() && lower.back() > word[i]) {
                    failed = true;
                    break;
                }
                marked[i] = 1;
                lower.push_back(word[i]);
            } else {
                if (!greater.empty() && greater.back() > word[i]) {
                    if (!lower.empty() && lower.back() > word[i]) {
                        failed = true;
                        break;
                    } else {
                        lower.push_back(word[i]);
                        marked[i] = 1;
                        continue;
                    }
                }
                greater.push_back(word[i]);
                marked[i] = 2;
            }
        }
        if (!failed && (lower.empty() || greater.empty() || lower.back() <= greater[0])) {
            for (int i = 1; i <= n; i++) {
                printf("%d", marked[i]);
            }
            printf("\n");
            return;
        }
    }
    printf("-\n");
}

int main() {
    
    scanf("%d", &t);
    while(t--) {
        test();
    }
    
    return 0;
}