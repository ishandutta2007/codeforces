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

const int N = 1000005;


struct Hash {
    int P, M;
    vector<int> H;
    vector<int> Hrev;
    vector<int> s;
    vector<int> pot;
    int n;
    
    Hash(char* c, int _n, int _P, int _M) {
        P = _P;
        M = _M;
        n = _n;
        H.resize(n + 2);
        Hrev.resize(n + 2);
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = c[i];
        }
        compHash();
    }
    
    Hash(int* c, int _n, int _P, int _M) {
        P = _P;
        M = _M;
        n = _n;
        H.resize(n + 2);
        Hrev.resize(n + 2);
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = c[i];
        }
        compHash();
    }
    
    Hash(vector<int> c, int _P, int _M) {
        P = _P;
        M = _M;
        n = (int)c.size() - 1;
        H.resize(n + 2);
        Hrev.resize(n + 2);
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = c[i];
        }
        compHash();
    }
    
    void compHash() {
        pot.resize(n + 2);
        pot[0] = 1;
        for (int i = 1; i <= n; i++) {
            pot[i] = (long long)pot[i - 1] * P % M;
        }
        for (int i = 1; i <= n; i++) {
            H[i] = ((long long)H[i - 1] * P + s[i]) % M;
        }
        for (int i = n; i >= 1; i--) {
            Hrev[i] = ((long long)Hrev[i + 1] * P + s[i]) % M;
        }
    }
    
    int getHash(int from, int to) {
        int l = to - from + 1;
        return ((H[to] - (long long)H[from - 1] * pot[l] % M) + M) % M;
    }
    
    int getHashRev(int from, int to) {
        int l = to - from + 1;
        return ((Hrev[from] - (long long)Hrev[to + 1] * pot[l] % M) + M) % M;
    }
    
    bool equal(int fromA, int toA, int fromB, int toB) {
        int lenA = toA - fromA + 1;
        int lenB = toB - fromB + 1;
        if (lenA != lenB) {
            return false;
        }
        return getHash(fromA, toA) == getHash(fromB, toB);
    }
    
    bool isPalindrome(int from, int to) {
        return getHash(from, to) == getHashRev(from, to);
    }
    
};


int n;
char s[N];

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &s[1]);
        n = strlen(s + 1);
        
        int low = 1;
        int high = n;
        while (low <= high && s[low] == s[high]) {
            low++;
            high--;
        }
        
        if (low > high) {
            printf("%s\n", s + 1);
            continue;
        }
        
        int len = high - low + 1;
        Hash h(s + low - 1, len, 257, 1021112333);
        
        int best = 0;
        int kt = -1;
        for (int i = len; i >= 1; i--) {
            if (h.isPalindrome(1, i)) {
                best = i;
                kt = 1;
                break;
            }
        }
        
        for (int i = 1; i <= len; i++) {
            if (h.isPalindrome(i, len)) {
                if (len - i + 1 > best) {
                    kt = 2;
                    best = len - i + 1;
                }
                break;
            }
        }
        
        for (int i = 1; i < low; i++) {
            printf("%c", s[i]);
        }
        if (kt == 1) {
            for (int i = 1; i <= best; i++) {
                printf("%c", s[i + low - 1]);
            }
        } else {
            for (int i = 1; i <= best; i++) {
                printf("%c", s[high - best + i]);
            }
        }
        for (int i = high + 1; i <= n; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
        
//         cerr << low << " " << best << endl;
//         printf("%d\n", 2 * (low - 1) + best);
    }
    
    return 0;
}