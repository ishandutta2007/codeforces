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
const int N = 2000005;
int n;
char word[N];
int onesSum[N], zerosSum[N];
int lastChar[N], lastPos[N];
int main() {
    
    scanf("%d", &n);
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        onesSum[i] = onesSum[i - 1] + (word[i] == '1');
        zerosSum[i] = zerosSum[i - 1] + (word[i] == '0');
        lastChar[i] = word[i] != '?' ? word[i] : lastChar[i - 1];
        if (lastChar[i] == lastChar[i - 1] || lastChar[i - 1] == 0) {
            lastPos[i] = lastPos[i - 1];
        } else {
            lastPos[i] = i;
        }
    }
    
    for (int x = 1; x <= n; x++) {
        int w = 1;
        int ans = 0;
        while (w + x - 1 <= n) {
            if (onesSum[w + x - 1] - onesSum[w - 1] == 0 || zerosSum[w + x - 1] - zerosSum[w - 1] == 0) {
                ans++;
                w += x;
            } else {
                int low = w + 1;
                int high = w + x - 1;
                int res = w + x;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (onesSum[w + x - 1] - onesSum[mid - 1] == 0 || zerosSum[w + x - 1] - zerosSum[mid - 1] == 0) {
                        res = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                w = res;
//                 if (w + x - 1 > n) w = n + 1;
//                 else
//                 w = lastPos[w + x - 1];
            }
        }
        printf("%d ", ans);
    }
    printf("\n");
    
    return 0;
}