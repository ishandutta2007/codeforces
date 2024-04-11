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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1000005, P = 257, M = 1000000033;

char s[N], t[N];
int n, m;
int pot[N];
int hasz[N];

int getHash(int from, int to) {
    return ((hasz[to] - (long long)hasz[from - 1] * pot[to - from + 1] % M) + M) % M;
}

bool good(int zeroLen, int oneLen) {
    debug("good ", zeroLen, oneLen);
    int pos = 1;
    int myHash[2];
    myHash[0] = myHash[1] = -1;
    for (int ptr = 1; ptr <= n; ptr++) {
        if (s[ptr] == 0) {
            if (pos + zeroLen - 1 > m) {
                return false;
            }
            int gHash = getHash(pos, pos + zeroLen - 1);
            if (myHash[0] != -1 && gHash != myHash[0]) {
                return false;
            }
            myHash[0] = gHash;
            pos += zeroLen;
        } else {
            if (pos + oneLen - 1 > m) {
                return false;
            }
            int gHash = getHash(pos, pos + oneLen - 1);
            if (myHash[1] != -1 && gHash != myHash[1]) {
                return false;
            }
            myHash[1] = gHash;
            pos += oneLen;
        }
    }
    debug(myHash[0], myHash[1]);
    return myHash[0] == -1 || myHash[1] == -1 || myHash[0] != myHash[1];
}

int main() {
    
    scanf("%s", &s[1]);
    scanf("%s", &t[1]);
    n = strlen(s + 1);
    m = strlen(t + 1);
    
    pot[0] = 1;
    for (int i = 1; i <= m; i++) {
        pot[i] = (long long)pot[i - 1] * P % M;
    }
    for (int i = 1; i <= m; i++) {
        hasz[i] = ((long long)hasz[i - 1] * P + t[i] - 'a' + 1) % M;
        debug(hasz[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        s[i] -= '0';
    }
    if (s[1] == 1) {
        for (int i = 1; i <= n; i++) {
            s[i] = 1 - s[i];
        }
    }
    
    int cntZeros = 0;
    int cntOnes = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 0) {
            cntZeros++;
        } else {
            cntOnes++;
        }
    }
    
    int ans = 0;
    for (int i = 1; i < m; i++) {
        int zeroLen = i;
        if ((long long)zeroLen * cntZeros > m) continue;
        int sumOnesLen = m - zeroLen * cntZeros;
        if (sumOnesLen % cntOnes != 0) continue;
        if (sumOnesLen / cntOnes == 0) {
            continue;
        }
        if (good(i, (sumOnesLen / cntOnes))) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}