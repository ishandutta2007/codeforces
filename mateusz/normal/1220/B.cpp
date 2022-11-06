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

const int N = 1005;

int n;
int A[N];
int mul[N][N];

bool good(int v) {
    A[1] = v;
    for (int i = 2; i <= n; i++) {
        A[i] = mul[1][i] / A[1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i == j) continue;
            if ((long long)A[i] * (long long)A[j] >= mul[i][j]) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mul[i][j]);
        }
    }
    
    int gcd = mul[1][2];
    for (int i = 3; i <= n; i++) {
        gcd = __gcd(gcd, mul[1][i]);
    }
    
    vector<int> divs;
    for (int i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            divs.push_back(i);
            if (gcd / i != i) {
                divs.push_back(gcd / i);
            }
        } 
    }
    sort(divs.begin(), divs.end());
    
    int low = 0;
    int high = divs.size() - 1;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool g = good(divs[mid]);
        if (g) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    A[1] = divs[res];
    for (int i = 2; i <= n; i++) {
        A[i] = mul[1][i] / A[1];
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}