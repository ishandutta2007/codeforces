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

const int N = 100005;

int n;
int A[N], B[N], Asize, Bsize;
int tab[N];
vector<int> cnt[N];
int ptr[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        cnt[tab[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++) {
        cnt[i].push_back(n + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        int x = tab[i];
        if (x != A[Asize] && x == B[Bsize]) {
            A[++Asize] = x;
        } else if (x == A[Asize] && x != B[Bsize]) {
            B[++Bsize] = x;
        } else if (x != A[Asize] && x != B[Bsize]) {
            int a = A[Asize];
            int b = B[Bsize];
            if (cnt[a][ptr[a]] < cnt[b][ptr[b]]) {
                A[++Asize] = x;
            } else {
                B[++Bsize] = x;
            }
        }
        ptr[x]++;
    }
    
    printf("%d\n", Asize + Bsize);
    
    return 0;
}