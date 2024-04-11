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

const int N = 2005;

int n;
long long X[N], Y[N];
int t[N];
char word[N];

long long det(int a, int b, int c) {
    return X[a] * Y[b] + X[b] * Y[c] + X[c] * Y[a] - Y[a] * X[b] - Y[b] * X[c] - Y[c] * X[a];
}

bool cmp(int a, int b) {
    return make_pair(X[a], Y[a]) < make_pair(X[b], Y[b]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &X[i], &Y[i]);
        t[i] = i;
    }
    
    scanf("%s", &word[2]);
    
    sort(t + 1, t + 1 + n, cmp);
    
    vector<int> pts;
    int first = t[1];
    pts.push_back(first);
    for (int i = 2; i <= n - 1; i++) {
        if (word[i] == 'L') {
            int best = i;
            for (int j = i + 1; j <= n; j++) {
                if (det(t[i - 1], t[best], t[j]) < 0) {
                    best = j;
                }
            }
            pts.push_back(t[best]);
            swap(t[i], t[best]);
        } else {
            int best = i;
            for (int j = i + 1; j <= n; j++) {
                if (det(t[i - 1], t[best], t[j]) > 0) {
                    best = j;
                }
            }
            pts.push_back(t[best]);
            swap(t[i], t[best]);
        }
    }
//     for (int i = 2; i <= n - 1; i++) {
//         if (word[i] == 'L') {
//             assert(det(t[i - 1], t[i], t[i + 1]) > 0);
//         } else {
//             assert(det(t[i - 1], t[i], t[i + 1]) < 0);
//         }
//     }
    pts.push_back(t[n]);
    for (int x : pts) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}